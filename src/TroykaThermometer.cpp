/****************************************************************************/
//  Function:       cpp file for TroykaThermometer
//  Hardware:       TMP36
//  Arduino IDE:    Arduino 1.8.3
//  Author:         Igor Dementiev
//  Date:           Jan 17, 2018
//  Version:        v1.0.0
//  by www.amperka.ru
/****************************************************************************/

#include "TroykaThermometer.h"

#define SAMPLE_TIMES    32

TroykaThermometer::TroykaThermometer(uint8_t pin) {
    _pin = pin;
}

void TroykaThermometer::read() {
    int sensorADC = 0;
    float sensorVoltage = 0;
    for (int i = 0; i < SAMPLE_TIMES; i++) {
        sensorADC += analogRead(_pin);
    }
    sensorADC = sensorADC >> 5;
  	sensorVoltage = sensorADC * (OPERATING_VOLTAGE / ADC_VALUE_MAX);
    _sensorTemperatureC = (sensorVoltage - 0.5) * 100.0;
    _sensorTemperatureK = _sensorTemperatureC + CELSIUS_TO_KELVIN;
    _sensorTemperatureF = (_sensorTemperatureC * 9.0 / 5.0) + 32.0;
}

float TroykaThermometer::getTemperatureC() {
    return _sensorTemperatureC;
}

float TroykaThermometer::getTemperatureK() {
    return _sensorTemperatureK;
}

float TroykaThermometer::getTemperatureF() {
    return _sensorTemperatureF;
}