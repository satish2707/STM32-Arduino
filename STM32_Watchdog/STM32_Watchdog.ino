/*******************************************************************************************************************
 * @details   : This sketch demonstrates Watchdog Timer Functionality With STM32G4
 *
 * @authors   : Satish Kanawade (Embedded Software Developer)
 *
 * @copyright : Embedlogiclancer
 *
 * @date      : 20 MAY 2024
 *
 * @version   : V1.0
 *
 * @file      : STM32_Watchdog.ino
 ********************************************************************************************************************/
#include <IWatchdog.h>
#include <Arduino.h>
#include <HardwareSerial.h>
#include "E_Watchdog.h"

// Debug serial port
HardwareSerial myDebug(USART1);

void setup() {
  // Initilize the Debug UART
  myDebug.begin(115200);

  // Initialize the Watchdog Timer
  Watchdog_init();
}

void loop() {
  // Reload the Watchdog in Every Cycle
  Reload_Watchdog();
}
