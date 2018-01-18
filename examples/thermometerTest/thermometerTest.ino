// библиотека для работы с аналоговым термометром (Troyka-модуль)
#include <TroykaThermometer.h>

// создаём объект для работы с аналоговым термометром
// и передаём ему номер пина выходного сигнала
TroykaThermometer thermometer(A1);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
}

void loop()
{
  // считываем данные с аналогового термометра
  thermometer.readData();
  // вывод показателей аналогового термометра в градусах Цельсия
  Serial.print("Temperature is ");
  Serial.print(thermometer.getTemperatureC());
  Serial.println(" C");
  // вывод показателей аналогового термометра в градусах Цельсия
  Serial.print("Temperature is ");
  Serial.print(thermometer.getTemperatureK());
  Serial.println(" K");
  // вывод показателей аналогового термометра в градусах Цельсия
  Serial.print("Temperature is ");
  Serial.print(thermometer.getTemperatureF());
  Serial.println(" F");
  delay(1000);
}
