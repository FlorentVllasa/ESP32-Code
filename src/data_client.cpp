#include "MPU9250.h"
#include "data_client.h"
#include <WiFi.h>

MPU9250 IMU(Wire,0x68);
int status;

WiFiClient client;
const uint16_t port = 8080;
const char* host = "192.168.2.114";

void setup_gyro(){

  status = IMU.begin();
  Serial.println(status);
  IMU.setGyroRange(MPU9250::GYRO_RANGE_2000DPS);
  IMU.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_184HZ);
  IMU.setAccelRange(MPU9250::ACCEL_RANGE_16G);
  IMU.calibrateGyro();
  IMU.calibrateAccel();
  IMU.setSrd(0);
}

void send_data_to_server(){

  IMU.readSensor();

  float gX = IMU.getGyroX_rads();
  float gY = IMU.getGyroY_rads();
  float gZ = IMU.getGyroZ_rads();

  float aX = IMU.getAccelX_mss();
  float aY = IMU.getAccelY_mss();
  float aZ = IMU.getAccelZ_mss();

  if(!client.connect(host, port)){
    Serial.println("Connection to host failed");
    delay(4000);
    return;
  }
  Serial.println("Connected to Server successfully!");


  client.print("G gx:");
  client.print(gX);
  client.print("G gy:");
  client.print(gY);
  client.print("G gz:");
  client.print(gZ);
  client.print("A ax:");
  client.print(aX);
  client.print("A ay:");
  client.print(aY);
  client.print("A az:");
  client.print(aZ);
}