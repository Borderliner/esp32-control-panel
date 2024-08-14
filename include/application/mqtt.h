#include "config/mqtt.h"

#include <WiFiClientSecure.h>
#include <PubSubClient.h>

namespace application::mqtt {
static bool is_initialized = false;

static WiFiClientSecure espClient;
static PubSubClient client(espClient);

void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    for (int i = 0; i < length; i++) {
        Serial.print((char) payload[i]);
    }
    Serial.println();
    Serial.println("-----------------------");
}

void setup_mqtt() {
    espClient.setCACert(ca_cert.c_str());
    client.setServer(mqtt_broker.c_str(), mqtt_port);
    client.setCallback(callback);

    while (!client.connected()) {
        String client_id = "esp32-client-";
        client_id += String(WiFi.macAddress());
        Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
        if (client.connect(client_id.c_str(), mqtt_username.c_str(), mqtt_password.c_str())) {
            Serial.println("Public EMQX MQTT broker connected");
            is_initialized = true;
        } else {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }

    client.publish(application::mqtt::mqtt_topic.c_str(), "Hi, I'm ESP32 ^^");
    client.subscribe(application::mqtt::mqtt_topic.c_str());
}
}
