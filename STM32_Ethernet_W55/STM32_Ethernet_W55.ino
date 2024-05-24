/*******************************************************************************************************************
 * @details   : Contains the Ethernet Driver functionality for STM32G484CET6 with Arduino Platform.
 *
 * @authors   : Satish Kanawade (Embedded Software Developer)
 *
 * @copyright : Embedlogiclancer
 *
 * @date      : 24 May 2024
 *
 * @version   : V1.0
 *
 * @file      : STM32_Ethernet_W55.ino
 ********************************************************************************************************************/
#include <SPI.h>
#include <Ethernet2.h>
#include "HardwareSerial.h"
#include "Ethernet_W55.h"

// Debug serial UART3
HardwareSerial Mydebug(USART1);

void setup() {
  // Initialize debug serial communication
  Mydebug.begin(115200);

  // Delay for stability
  delay(1000);

  // Initialize Ethernet connection
  EthernetInit();
}

void loop() {
  // Check Ethernet link status
  linkstatus();
}
