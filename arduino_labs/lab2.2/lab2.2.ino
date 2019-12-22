/*Указываем вывод порта к которому подключен датчик*/
#define PinData 5
int humidity;     // Влажность
int temperature;  // Температура

void setup() {
Serial.begin(9600);
pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
digitalWrite(LED_BUILTIN, LOW); /*выключим светодиод*/
delay(500);
int result = getTempHumDHT11();
digitalWrite(LED_BUILTIN, HIGH); /*включим светодиод, когда данные будут готовы*/
delay(500);
/*вывод результата в монитор*/
Serial.print(humidity);
Serial.println(" %");
Serial.print(temperature);
Serial.println(" *C");
}
/*Функция считывания данных с датчика DHT11*/
int getTempHumDHT11() {
int dataDHT[5];
//1 этап
pinMode(PinData, OUTPUT);
digitalWrite(PinData, LOW);
delay(18);
digitalWrite(PinData, HIGH);
delayMicroseconds(40);
pinMode(PinData, INPUT);
//2 этап
delayMicroseconds(10);
if(digitalRead(PinData) == HIGH) return -1;
delayMicroseconds(70);
if(digitalRead(PinData) == LOW) return -1;
while(digitalRead(PinData) == HIGH){};
//3 этап
for (int j = 0; j < 5; j++)
{
  dataDHT[j] = 0;
  for (int i = 0; i < 8; i++)
  {
    while (digitalRead(PinData) == LOW){};
    delayMicroseconds(30);
    if (digitalRead(PinData) == HIGH) dataDHT[j] |= 1 << (7 - i);
    while (digitalRead(PinData) == HIGH){};
  }
}
delayMicroseconds(50);
/*проверка контрольной суммы*/
int sum = dataDHT[0] + dataDHT[1] + dataDHT[2] + dataDHT[3];
if (dataDHT[4] != sum) return -1;
/*для DHT11 дробная часть равна нулю, поэтому возвращаем только целые значения*/
humidity = dataDHT[0];
temperature = dataDHT[2];
return 0;
}