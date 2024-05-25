/*******************************************************************************************************************
 * @details   : This sketch demonstrates ZMPT Module Interface with STM32 for Measure AC voltage 
 *
 * @authors   : Satish Kanawade (Embedded Software Developer)
 *
 * @copyright : Embedlogiclancer
 *
 * @date      : 20 JUNE 2023
 *
 * @version   : V1.0
 *
 * @file      : ZMPT_with_STM32.ino
 ********************************************************************************************************************/
 
#include "voltmeter.h"

float testFrequency = 50;
float windowLength = 40.0 / testFrequency;

int Sensor = PA0;

float intercept = -0.04;
float slope = 0.0405;
float current_Volts;

void setup() {
  setupVoltmeter();
}

void loop() {
  voltmeterLoop();
}

#include "ZMPT101B.h"
#include "E_ANALOG.h"
#include "HardwareSerial.h"

// Debug serial port
HardwareSerial myDebug(USART1);

void setup() {
  myDebug.begin(115200);
}

void loop() {
  uint16_t VoltageReading = ACvoltageIs();
  myDebug.print("AC voltage is :");
  myDebug.println(VoltageReading);
}
