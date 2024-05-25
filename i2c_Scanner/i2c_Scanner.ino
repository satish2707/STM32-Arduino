/*******************************************************************************************************************
 * @details   : This sketch demonstrates Scan the i2c device on BUS
 *
 * @authors   : Satish Kanawade (Embedded Software Developer)
 *
 * @copyright : Embedlogiclancer
 *
 * @date      : 23 NOV 2022
 *
 * @version   : V1.0
 *
 * @file      : i2c_Scanner.ino
 ********************************************************************************************************************/
#include "Arduino.h"
#include "Wire.h"
#include <HardwareSerial.h>

HardwareSerial myDebug(USART1);
TwoWire myWire(PB7, PA15);

#define URTCLIB_WIRE myWire

void setup() {
  myWire.begin();
  myDebug.begin(115200);
}

void loop() {
  byte error, address;
  int nDevices;

  myDebug.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++) {
    myWire.beginTransmission(address);
    error = myWire.endTransmission();

    if (error == 0) {
      myDebug.print("I2C device found at address 0x");
      if (address < 16)
        myDebug.print("0");
      myDebug.print(address, HEX);
      myDebug.println("  !");

      nDevices++;
    } else if (error == 4) {
      myDebug.print("Unknown error at address 0x");
      if (address < 16)
        myDebug.print("0");
      myDebug.println(address, HEX);
    }
  }
  if (nDevices == 0)
    myDebug.println("No I2C devices found\n");
  else
    myDebug.println("done\n");

  delay(5000);  // wait 5 seconds for next scan
}
