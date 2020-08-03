
#include <ArduinoOTA.h>
#include "wifi_con.h"
//#include "gyro_test.h"
#include "data_client.h"

void setup() {
  Serial.begin(115200);
  try_wifi_connection();
  setup_gyro();
}

void loop() {
  ArduinoOTA.handle();
  //print_gyro_data();
  send_data_to_server();
}