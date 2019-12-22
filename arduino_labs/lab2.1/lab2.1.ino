/*Указываем вывод порта к которому подключен датчик*/
#define DHT_PORT PORTD
#define DHT_DDR DDRD
#define DHT_PIN PIND
#define DHT_BIT 5
uint8_t humidity, temperature; /*значение влажности и температуры*/
uint8_t dht_read();
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
 digitalWrite(LED_BUILTIN, LOW); /*выключим светодиод*/
  delay(500);
  dht_read();
 digitalWrite(LED_BUILTIN, HIGH); /*включим светодиод, когда данные будут готовы*/
  delay(500);
 /*вывод результата в монитор*/
  Serial.print(humidity);
  Serial.println(" %");
  Serial.print(temperature);
  Serial.println(" *C");
}
/*Функция считывания данных с датчика DHT11*/
uint8_t dht_read() {
 uint8_t datadht[5]; /*массив для значений датчика*/

 /*1.*/
 DHT_DDR |= (1 << DHT_BIT); /*настраиваем вывод на выход*/
 DHT_PORT &= ~(1 << DHT_BIT); /*низкий уровень — подтягиваем линию-разбудим датчик*/
 _delay_ms (18); /*18 мс - старт*/
 cli(); /*запрещаем прерывания*/
 DHT_PORT |= (1 << DHT_BIT); /*отпускаем линию*/
  _delay_us (40);

 /*2.*/
 DHT_DDR &= ~(1 << DHT_BIT); /*настраиваем вывод на вход*/
  _delay_us(10);
 if (DHT_PIN & (1 << DHT_BIT)) { return -1; } /*датчик должен ответить "0"*/
  _delay_us(80);
 if (!(DHT_PIN & (1 << DHT_BIT))) { return -1; } /*по истечению 80 мкс, датчик должен отпустить шину*/

 /*3.*/
 while (DHT_PIN & (1 << DHT_BIT)); /*ожидаем пока контроллер датчика начнет передавать данные*/
 /*передача начинается с нуля*/
 for (uint8_t j = 0; j < 5; j++) { /*считваем 5 байт*/
  datadht[j] = 0;
 for (uint8_t i = 0; i < 8; i++) { /*считываем побитово*/

 while (!(DHT_PIN & (1 << DHT_BIT))); /*ожидаем когда датчик отпустит шину*/
 _delay_us(30); /*задержка высокого уровня на 30 мкс*/
 if (DHT_PIN & (1 << DHT_BIT)) /*если по истечению времени сигнал на линии высокий, значит передается "1"*/
 datadht[j] |= 1 << (7 - i); /*тогда i-й бит устанавливаем в "1"*/
 while (DHT_PIN & (1 << DHT_BIT)); /*ждем окончание "1" */
}}
 sei(); /* разрешаем общее прерывание*/
_delay_us(50);

 /*4.*/
 /*проверка контрольной суммы*/
uint8_t sum = datadht[0] + datadht[1] + datadht[2] + datadht[3];
if (datadht[4] != sum) return -1;

 /*для DHT11 дробная часть равна нулю, поэтому возвращаем только целые значения*/
humidity = datadht[0];
temperature = datadht[2];

return 0;
}