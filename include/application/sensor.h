#pragma once

namespace application::sensor {
struct Sensor {};

class TemperatureSensor: Sensor {
public:
    virtual float read_temperature() = 0;
};

class HumiditySensor: Sensor {
public:
    virtual float read_humidity() = 0;
};

class PressureSensor: Sensor {
public:
    virtual float read_pressure() = 0;
};

class AltitudeSensor: Sensor {
public:
    virtual float read_altitude() = 0;
};
}
