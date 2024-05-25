/*******************************************************************************************************************
 * @details   : This Project demonstrates the RTC DS3231 Interfaces with STM32G484CET6
 *
 * @authors   : Satish Kanawade (Embedded Software Developer)
 *
 * @copyright : Embedlogiclancer
 *
 * @date      : 12 JAN 2024
 *
 * @version   : V1.0
 *
 * @file      : DS3231_STM32G4.ino
 ********************************************************************************************************************/
#include "Arduino.h"
#include "Wire.h"
#include "uRTCLib.h"
#include <HardwareSerial.h>

HardwareSerial myDebug(USART1);
uRTCLib rtc(0x68, URTCLIB_MODEL_DS3231);

char RTCDateTime[64];  // Buffer for formatted date and time (e.g., YYYY-MM-DD HH:MM:SS)
char RTCDate[64];      // Buffer for formatted date and time (e.g., YYYY-MM-DD )
char RTCTime[12];      // Buffer for formatted date (e.g., HH:MM:SS)
char RTCDay[9];        // Buffer for formatted Day (e.g., Sun,Mon)

void setup() {

  URTCLIB_WIRE.setSDA(PB7);
  URTCLIB_WIRE.setSCL(PA15);
  myDebug.begin(115200);

  myDebug.println("DS3231 Initialize Successfully");

#ifdef ARDUINO_ARCH_ESP8266
  URTCLIB_WIRE.begin(0, 2);  // D3 and D4 on ESP8266
#else
  URTCLIB_WIRE.begin();
#endif

  rtc.set(00, 51, 05, 2, 18, 12, 23);
  //  RTCLib::set(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)
}
const char *getAbbreviatedDayOfWeekString(int dow) {
  switch (dow) {
    case 1:
      return "Sun";
    case 2:
      return "MON";
    case 3:
      return "TUE";
    case 4:
      return "WED";
    case 5:
      return "THU";
    case 6:
      return "FRI";
    case 7:
      return "SAT";
    default:
      return "Invalid Day";
  }
}

void loop() {
  rtc.refresh();

  sprintf(RTCDateTime, "20%02d-%02d-%02d %02d:%02d:%02d", rtc.year(), rtc.month(), rtc.day(), rtc.hour(), rtc.minute(), rtc.second());

  sprintf(RTCDate, "20%02d%02d%02d", rtc.year(), rtc.month(), rtc.day());

  sprintf(RTCTime, "%02d:%02d:%02d", rtc.hour(), rtc.minute(), rtc.second());

  strcpy(RTCDay, getAbbreviatedDayOfWeekString(rtc.dayOfWeek()));

  myDebug.println(RTCDateTime);

  myDebug.println(RTCDate);

  myDebug.println(RTCTime);

  myDebug.println(RTCDay);

  delay(1000);
}
