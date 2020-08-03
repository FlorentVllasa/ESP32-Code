#include <MPU9250_asukiaaa.h>
#include "wifi_con.h"
#include <WiFi.h>
//#include <iostream>

#define SDA_PIN 26
#define SCL_PIN 25

// WiFiClient client;
MPU9250_asukiaaa mySensor;
float gX, gX_old, gY, gZ, aX, aY, aZ;
// const uint16_t port = 8080;
// const char* host = "192.168.2.114";

void setup_gyro_2(){
    //int is_connected = client.connect(host, port);

    Wire.begin(SDA_PIN, SCL_PIN);
    Wire.setClock(240000);
    mySensor.setWire(&Wire);
    mySensor.beginGyro();
    mySensor.beginAccel();

    // if(!is_connected){
    //     Serial.println("Connection to host failed");
    //     delay(4000);
    //     return;
    // }
    // Serial.println("Connected to Server successfully!");
}

void print_gyro_data_2(){

    mySensor.gyroUpdate();
    gX = mySensor.gyroX();
    gY = mySensor.gyroY();
    gZ = mySensor.gyroZ();

    // if(!client.connect(host, port)){
    //     Serial.println("Connection to host failed");
    //     delay(4000);
    //     return;
    // }
    // Serial.println("Connected to Server successfully!");
    // if (!client.connected()) {
    //     Serial.println();
    //     Serial.println("disconnecting from server.");
    //     client.stop();

    //     // do nothing forevermore:
    //     while (true);
    // }
    
    // client.print("Vector x:");
    // client.print(gX);
    // client.print("Vector y:");
    // client.print(gY);
    // client.print("Vector z:");
    // client.print(gZ);

    // while (client.available()) {
    //     Serial.println("client available");
    //     client.print(vector.x);
    // }

    // if (!client.connected()) {
    //     Serial.println();
    //     Serial.println("disconnecting from server.");
    //     client.stop();

    //     // do nothing forevermore:
    //     while (true);
    // }

    //mySensor.accelUpdate();
    //aX = mySensor.accelX();
    //aY = mySensor.accelY();
    //aZ = mySensor.accelZ();
}