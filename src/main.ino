
#include "BluetoothSerial.h"
String device_name = "ESP32-BT-Slave";
int manual_light = 1;
BluetoothSerial SerialBT;
byte receiveData;
#define LIGHT_SENSOR_PIN 15
#define RELAY_PIN1 13
#define RELAY_PIN2 12
#define RELAY_PIN3 4
#define RELAY_PIN4 2
void setup() {


  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  pinMode(RELAY_PIN1, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);
  pinMode(RELAY_PIN3, OUTPUT);
  pinMode(RELAY_PIN4, OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);

  digitalWrite(RELAY_PIN1, HIGH);
  digitalWrite(RELAY_PIN2, HIGH);
  digitalWrite(RELAY_PIN3, HIGH);
  digitalWrite(RELAY_PIN4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*if (Serial.available()) {
    /SerialBT.write(Serial.read());
    }
    if (SerialBT.available()) {
    Serial.write(SerialBT.read());
    }
    delay(20);*/
  /*int digitalValue = digitalRead(LIGHT_SENSOR_PIN);

    Serial.print("Digital Value = ");
    Serial.println(digitalValue);

    if(manual_light == 1) {
    if(digitalValue == 1){
     digitalWrite(RELAY_PIN4, LOW);
    }
    else{
    digitalWrite(RELAY_PIN4, HIGH);
    }
    }*/

  if (SerialBT.available()) {
    receiveData = SerialBT.read();
    Serial.write(receiveData);
    if (receiveData == 48) {
      digitalWrite(RELAY_PIN1, LOW);
    }
    if (receiveData == 49) {
      digitalWrite(RELAY_PIN1, HIGH);
    }
    if (receiveData == 50) {
      digitalWrite(RELAY_PIN2, LOW);
    }
    if (receiveData == 51) {
      digitalWrite(RELAY_PIN2, HIGH);
    }
    if (receiveData == 52 ) {
      digitalWrite(RELAY_PIN3, LOW);
    }
    if (receiveData == 53 ) {
      digitalWrite(RELAY_PIN3, HIGH);
    }
    if (receiveData == 54) {
      digitalWrite(RELAY_PIN4, LOW);
      manual_light = 0;
    }
    if (receiveData == 55) {
      digitalWrite(RELAY_PIN4, HIGH);
      manual_light = 1;
    }
  }
}
