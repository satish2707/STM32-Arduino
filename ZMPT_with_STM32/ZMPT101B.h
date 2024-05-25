/************************************************************************************************
 * @file      : ZMPT101B.h
 *
 * @author    : Satish Kanawade (Embedded Software developer)
 *
 * @brief     : Contains the application main logic and functionality..
 *
 * @copyright : Embedlogiclancer
 *
 * @date      : 20 JUNE 2023
 *
 ************************************************************************************************/
 
#ifndef ZMPT101B_h
#define ZMPT101B_h

#include <Arduino.h>

#define DEFAULT_FREQUENCY 50.0f
#define DEFAULT_SENSITIVITY 500.0f
#define ADC_SCALE 4095.0
#define VREF 3.3

class ZMPT101B {
public:
  // Constructor to initialize the ZMPT101B object with specified pin and frequency
  ZMPT101B(uint8_t pin, uint16_t frequency = DEFAULT_FREQUENCY);

  // Set the sensitivity of the sensor
  void setSensitivity(float value);

  // Get the AC voltage based on the specified loop count
  float getVoltage(uint8_t loopCount = 1);

private:
  // Member variables
  uint8_t pin;
  uint32_t period;
  float sensitivity = DEFAULT_SENSITIVITY;

  // Private function to get the zero point of the sensor
  int getZeroPoint();
};

#endif
