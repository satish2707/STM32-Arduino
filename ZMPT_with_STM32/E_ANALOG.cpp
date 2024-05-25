/***********************************************************************************************
 * @file      : E_ANALOG.cpp
 *
 * @details   : This file contains the AC Voltage 
 *
 * @author    : Satish Kanawade (Embedded Software developer)
 *
 * @copyright : Embedlogiclancer
 *
 * @date      : 20 JUNE 2023
 *
 **********************************************************************************************/
 
#include <ZMPT101B.h>
#include "E_ANALOG.h"

// Create an instance of ZMPT101B voltage sensor
ZMPT101B voltageSensor(PA0, 50.0);

// Function to measure and calculate AC voltage
uint16_t ACvoltageIs(void) {
  voltageSensor.setSensitivity(590);
  return floor(voltageSensor.getVoltage(5));
}
