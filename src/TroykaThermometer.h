/****************************************************************************/
//  Function:       Header file for TroykaThermometer
//  Hardware:       TMP36
//  Arduino IDE:    Arduino 1.8.3
//  Author:         Igor Dementiev
//  Date:           Jan 17, 2018
//  Version:        v1.0.0
//  by www.amperka.ru
/****************************************************************************/

#ifndef TROYKA_THERMOMETR_H_
#define TROYKA_THERMOMETR_H_

#include <Arduino.h>

#define ADC_BIT             10

#define ADC_VALUE_MAX       pow(2, ADC_BIT)

#if defined(__AVR__)
#define OPERATING_VOLTAGE   5.0

#elif defined(__SAM3X8E__) || defined(__SAM3A8C__) || defined(__SAM3A4C__) || defined(__SAMD21G18A__) || defined(ARDUINO_ARCH_ESP8266) || defined(__arm__)
#define OPERATING_VOLTAGE   3.3
#endif

#define CELSIUS_TO_KELVIN	273.15

class TroykaThermometer
{
public:
    TroykaThermometer(uint8_t pin);
    void read();
    float getTemperatureC();
    float getTemperatureK();
    float getTemperatureF();
private:
    uint8_t _pin;
    float _sensorTemperatureC;
    float _sensorTemperatureK;
    float _sensorTemperatureF;
};
#endif  // TROYKA_THERMOMETR_H_
