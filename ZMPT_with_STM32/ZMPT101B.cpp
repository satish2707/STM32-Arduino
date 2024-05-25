/************************************************************************************************
 * @file      : ZMPT101B.cpp
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

#include "ZMPT101B.h"

// Constructor to initialize the ZMPT101B object with specified pin and frequency
ZMPT101B::ZMPT101B(uint8_t pin, uint16_t frequency) {
  this->pin = pin;
  period = 1000000 / frequency;
  pinMode(pin, INPUT);
  analogReadResolution(12);
}

// Set the sensitivity of the sensor
void ZMPT101B::setSensitivity(float value) {
  sensitivity = value;
}

// Get the zero point of the sensor for calibration
int ZMPT101B::getZeroPoint() {
  uint32_t Vsum = 0;
  uint32_t measurements_count = 0;
  uint32_t t_start = micros();

  // Measure voltage over a period to determine zero point
  while (micros() - t_start < period) {
    Vsum += analogRead(pin);
    measurements_count++;
  }

  return Vsum / measurements_count;
}

// Get the AC voltage based on specified loop count for improved accuracy
float ZMPT101B::getVoltage(uint8_t loopCount) {
  double readingVoltage = 0.0f;

  // Iterate through specified loop count for more accurate measurement
  for (uint8_t i = 0; i < loopCount; i++) {
    int zeroPoint = this->getZeroPoint();

    int32_t Vnow = 0;
    uint32_t Vsum = 0;
    uint32_t measurements_count = 0;
    uint32_t t_start = micros();

    // Measure voltage over a period for accurate RMS calculation
    while (micros() - t_start < period) {
      Vnow = analogRead(pin) - zeroPoint;
      Vsum += (Vnow * Vnow);
      measurements_count++;
    }

    // Calculate RMS voltage and accumulate for averaging
    readingVoltage += sqrt(Vsum / measurements_count) / ADC_SCALE * VREF * sensitivity;
  }

  // Return the averaged RMS voltage over the specified loop count
  return readingVoltage / loopCount;
}
