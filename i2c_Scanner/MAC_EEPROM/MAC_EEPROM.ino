
/*******************************************************************************************************************
 * @details   : This Firmware that read the MAC ID from EEPROM (MCP 24AA025E48)
 *
 * @authors   : Satish Kanawade (Embedded Software Developer)
 *
 * @copyright : Embedlogiclancer
 *
 * @date      : 14 DEC 2023
 *
 * @version   : V1.0
 *
 * @file      : MAC_EEPROM.ino
 ********************************************************************************************************************/
#include "Arduino.h"
#include "Wire.h"
#include <HardwareSerial.h>

HardwareSerial myDebug(USART1);
TwoWire myWire(PB7, PA15);
#define EEPROM_ADDRESS 0x50

#define URTCLIB_WIRE myWire

void setup() 
{
  myWire.begin();
  myDebug.begin(115200);
  myDebug.println("EEPROM connected!");
}
void loop()
{
  uint8_t mac[6];
  char macBuffer[18]; // Buffer for storing MAC address in the format "XX:XX:XX:XX:XX:XX"

  // Read MAC address from EEPROM address 0xFA
  myWire.beginTransmission(EEPROM_ADDRESS);
  myWire.write(0xFA); // Starting address of MAC in EEPROM
  myWire.endTransmission();

  myWire.requestFrom(EEPROM_ADDRESS, 6); // Request 6 bytes (MAC address length)
  for (int i = 0; i < 6; i++) {
    mac[i] = myWire.read();
  }

  // Format MAC address as a string
  sprintf(macBuffer, "%02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

  myDebug.print("MAC address at 0xFA: ");
  myDebug.println(macBuffer);

  delay(1000); // Delay added for stability, adjust as needed
}
