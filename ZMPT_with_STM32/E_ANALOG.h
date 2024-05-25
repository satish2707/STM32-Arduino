/*********************************************************************************************
 * @file      : E_ANALOG.h
 *
 * @author    : Satish Kanawade (Embedded Software developer)
 *
 * @brief     : This file contains the Analog feature control of the project.
 *
 * @copyright : Embedlogiclancer
 *
 * @date      : 20 JUNE 2023
 *
 *********************************************************************************************/

#ifndef _E_ANALOG_H_
#define _E_ANALOG_H_

#include <Filters.h>

extern HardwareSerial myDebug;

uint16_t ACvoltageIs(void);
/**
 * @brief Function prototype to measure and calculate AC voltage
 * @param None
 * @return  AC voltage.
 */

#endif
