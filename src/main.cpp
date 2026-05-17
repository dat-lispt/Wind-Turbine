#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;
// put function declarations here:
float shuntVoltage = 0;
float busVoltage = 0;
float loadVoltage = 0;
float current = 0;
int myFunction(int, int);

//Using INA219
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  int result = myFunction(2, 3);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
  ina219.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  shuntVoltage = ina219.getShuntVoltage_mV();
  busVoltage = ina219.getBusVoltage_V();
  loadVoltage = ina219.getPower_mW();
  current = ina219.getCurrent_mA(); 
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}