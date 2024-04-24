#pragma once

#include "application/sensor.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
// define USING_BME280_SPI in your main header if you're using it
#ifdef USING_BME280_SPI
    #include <SPI.h>
#endif

namespace application::sensor {
#define SEA_LEVEL_PRESSURE_HPA (1013.25)
#ifdef USING_BME280_SPI
    #define BME_SCK 18
    #define BME_MISO 19
    #define BME_MOSI 23
    #define BME_CS 5
#endif

class BME280:
    public TemperatureSensor,
    public HumiditySensor,
    public PressureSensor,
    public AltitudeSensor {
private: 
    Adafruit_BME280 sensor; // I2C

    //Adafruit_BME280 bme(BME_CS); // hardware SPI
    //Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI
public:
    bool is_initialized = false;

    BME280(uint8_t sda = 21, uint8_t scl = 22, uint8_t address = 0x76) {
        Wire.begin(sda, scl);
        bool status = sensor.begin(address);
        if (!status) {
            Serial.println("Could not find a valid BME280 sensor at given address, scanning other addresses...");
            uint8_t addr = scan_i2c_address();
            if (addr > 0) {
                status = sensor.begin(address);
                if (!status) {
                    Serial.println("Failed while trying to connect to scanned address value. Check wiring.");
                    Wire.end();
                }
            } else {
                Serial.println("Could not find a valid address to operate on. Maybe faulty sensor?");
                Wire.end();
            }
        } else {
            Serial.println("BME280 sensor initialized successfully.");
        }
        is_initialized = status;
    }
    
    ~BME280() {
        Wire.end();
        sensor.~Adafruit_BME280();
    }

    float read_temperature() override {
        return sensor.readTemperature();
    }

    float read_humidity() override {
        return sensor.readHumidity();
    }

    float read_pressure() override {
        return sensor.readPressure();
    }

    float read_altitude() override {
        return sensor.readAltitude(SEA_LEVEL_PRESSURE_HPA);
    }

    const Adafruit_BME280& get_sensor() { return sensor; }

    uint8_t scan_i2c_address() {
        Wire.begin();
        uint8_t error, address;
        uint8_t nDevices;
        Serial.println("Scanning for BME280 sensor...");
        nDevices = 0;
        for (address = 1; address < 127; address++ ) {
            Wire.beginTransmission(address);
            error = Wire.endTransmission();
            if (error == 0) {
                Serial.print("I2C device found at address 0x");
                if (address < 16) {
                    Serial.print("0");
                }
                Serial.println(address,HEX);
                nDevices++;
            }
            else if (error == 4) {
                Serial.print("Unknow error at address 0x");
                if (address < 16) {
                    Serial.print("0");
                }
                Serial.println(address,HEX);
            }
        }
        if (nDevices == 0) {
            Serial.println("No I2C devices found\n");
            loop_scan_i2c_address();
        }
        else {
            Serial.println("done\n");
        }

        return address;
    }

    uint8_t loop_scan_i2c_address() {
        Wire.begin();
        uint8_t error, address;
        uint8_t nDevices;
        Serial.println("Scanning for BME280 sensor...");
        nDevices = 0;
        
        while (nDevices < 1) {
            for (address = 1; address < 127; address++ ) {
                Wire.beginTransmission(address);
                error = Wire.endTransmission();
                if (error == 0) {
                    Serial.print("I2C device found at address 0x");
                    if (address < 16) {
                        Serial.print("0");
                    }
                    Serial.println(address,HEX);
                    nDevices++;
                }
                else if (error == 4) {
                    Serial.print("Unknow error at address 0x");
                    if (address < 16) {
                        Serial.print("0");
                    }
                    Serial.println(address,HEX);
                }
            }
            if (nDevices == 0) {
                Serial.println("No I2C devices found\n");
            }
            else {
                Serial.println("done\n");
            }
            delay(5000);
        }
        return nDevices;
    }
};

static BME280* bme280;
const BME280* setup_bme280() {
    bme280 = new BME280(21, 22, 0x76);
    if (bme280->is_initialized) {
        return bme280;
    } else {
        return nullptr;
    }
}
}
