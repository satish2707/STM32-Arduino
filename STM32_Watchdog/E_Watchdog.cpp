/**************************************************************************************************
 * @file: E_Watchdon.cpp
 *
 * @author: Satish Kanawade
 *
 * @brief: This file contains the Watchdog functionality of the project.
 *
 * @copyright: Emprotek Software Solutions Pvt Ltd 2023.
 *
 *************************************************************************************************/
#include <IWatchdog.h>
#include <Arduino.h>
#include <HardwareSerial.h>
#include "E_Watchdog.h"

extern HardwareSerial myDebug;

unsigned long durationMs = 32000000;

// Enable Watchdog for the desired duration in milliseconds
void Watchdog_init() {
  IWatchdog.begin(durationMs);
  if (!IWatchdog.isEnabled()) {
    myDebug.println("\nError: Watchdog timer is not enabled\n");
  } else {
    unsigned long durationSec = durationMs / 1000;

    myDebug.print("\nWatchdog timer enabled for: ");
    myDebug.print(durationSec);
    myDebug.println(" Milliseconds\n");
  }
}

// This Function Reload the watchdog in Given Duration
void Reload_Watchdog() {
  IWatchdog.reload();
}