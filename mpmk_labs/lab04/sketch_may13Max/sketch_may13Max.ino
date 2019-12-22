#include <avr/io.h>
//Подключаем заголовочный файл, в котором объявлена
//наша функция (и, если необходимо, еще что-то)
#include "asmroutine.h"
#define n 10
volatile char d = 0;
void setup() {
  volatile char m[n];
  Serial.begin(9600);
  //Вызываем ассемблерную функцию, которая
  //вернет максимальное значение.
  d = asm_func(m, n);
}
void loop() {
  for (int i = 0; i < n; i++)
  {
    if (Serial.available() > 0){
    
    }
  }
  // put your main code here, to run repeatedly:
  Serial.print("Max=");
  Serial.println(d, DEC);
}
