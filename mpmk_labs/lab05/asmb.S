;Включаем заголовочный файл, на случай, если
;в нем есть какие-либо необходимые определения
#include "asmroutine.h"
;Включаем заголовочный файл
#include "asmroutine.h"
;Экспортируем функцию led_effect
.global led_effect
led_effect:
;По схеме 4 светодиода подключены к порту B, биты 2,3,4,5         
sbi _DDRB, 2 ;Настраиваем на вывод информации 2 бит порта B
sbi _DDRB, 3 ;Настраиваем на вывод информации 3 бит порта B
sbi _DDRB, 4 ;Настраиваем на вывод информации 4 бит порта B
sbi _DDRB, 5 ;Настраиваем на вывод информации 5 бит порта B
sbi _PORTB, 2 ;Выдаем логическую "1" на 2 бит порта B
sbi _PORTB, 3 ;Выдаем логическую "1" на 3 бит порта B
sbi _PORTB, 4 ;Выдаем логическую "1" на 4 бит порта B
sbi _PORTB, 5 ;Выдаем логическую "1" на 5 бит порта B

Start:
ldi R26 , 0b00011000
out _PORTB, R26;
ldi R23, 0xFF ;Устанавливаем величину задержки
rcall delayx ;Вызов нашей функции задержки
ldi R26 , 0b00100100 
out _PORTB, R26;
ldi R23, 0xFF
rcall delayx
ldi R26 , 0b00010100 
out _PORTB, R26;
ldi R23, 0xFF
rcall delayx
ldi R26 , 0b00011000 
out _PORTB, R26;
ldi R23, 0xFF
rcall delayx

rjmp Start ;Зацикливаем
ret

delayx:
	push R26 ;В стеке сохраняем значение R26
	m1:
	ldi R26, 0xFF
	m2:
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	dec R26
	brne m2
	dec R27
	brne m1
	pop R26 ;В стеке сохраняем значение R26
	ret