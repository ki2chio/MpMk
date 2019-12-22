#include <avr/io.h>
//Подключаем заголовочный файл, в котором объявлена
//наша функция (и, если необходимо, еще что-то)
#include "asmroutine.h"
volatile char d;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  // asm_func_wait_1mks(m);
  // asm_func_wait_3_4mks(m);
  // asm_func_wait_5mks();
}
void loop() {
  static char input = '1';
  if (Serial.available() > 0)
  {
    input = Serial.read();
  }
  switch (input) {
    case '1':
      digitalWrite(LED_BUILTIN, LOW);
      asm_func_wait_1mks(1);
      digitalWrite(LED_BUILTIN, HIGH);
      asm_func_wait_5mks();
      asm_func_wait_5mks();
      break;
    case '2':
      digitalWrite(LED_BUILTIN, LOW);
      asm_func_wait_3_4mks(1);
      digitalWrite(LED_BUILTIN, HIGH);
      asm_func_wait_5mks();
      break;
    case '3':
      digitalWrite(LED_BUILTIN, LOW);
      break;
  }

}
