#include <avr/io.h>
//Подключаем заголовочный файл, в котором объявлена
//наша функция (и, если необходимо, еще что-то)
#include "asmroutine.h"
volatile char d = 0;
void setup() {
volatile char m[]={15,9,100};
Serial.begin(9600);
//Вызываем ассемблерную функцию, которая
//вернет максимальное значение. 
d=asm_func(&m[0]);
}
void loop() {
// put your main code here, to run repeatedly:
Serial.print("Max=");
Serial.println(d, DEC);
delay(600);
}