;Алгоритм светлодиодов изменен для большей наглядности роботы функции
;Включаем заголовочный файл, на случай, если
;в нем есть какие-либо необходимые определения
#include "asmroutine.h"
;Включаем заголовочный файл
#include "asmroutine.h"
;Экспортируем функцию key_change
	.global key_change
key_change:
	;Используем один светодиод
	sbi _DDRB, 2 ;Настраиваем на вывод информации 2 бит порта B
	sbi _DDRB, 3 ;Настраиваем на вывод информации 3 бит порта B
	sbi _DDRB, 4 ;Настраиваем на вывод информации 4 бит порта B
	sbi _DDRB, 5 ;Настраиваем на вывод информации 5 бит порта B
	sbi _PORTB, 2 ;Выдаем логическую "1" на 2 бит порта B
	sbi _PORTB, 3 ;Выдаем логическую "1" на 3 бит порта B
	sbi _PORTB, 4 ;Выдаем логическую "1" на 4 бит порта B
	sbi _PORTB, 5 ;Выдаем логическую "1" на 5 бит порта B
	;Используем одну кнопку
	cbi _DDRC, 2 ;Настраиваем на ввод информации 2 бит порта C
	sbi _PORTC, 2 ;Подаем логическую "1" на 2 бит порта C
Start:
	ldi R26 , 0b00011100
	out _PORTB, R26;
	ldi R23, 0xFF ;Устанавливаем величину задержки
	rcall delayx ;Вызов нашей функции задержки
	ldi R26 , 0b00101100 
	out _PORTB, R26;
	ldi R23, 0xFF
	rcall delayx
	ldi R26 , 0b00110100 
	out _PORTB, R26;
	ldi R23, 0xFF
	rcall delayx
	ldi R26 , 0b00111000 
	out _PORTB, R26;
	ldi R23, 0xFF
	rcall delayx
m1:
	
	nop
	sbis _PINC, 2
	rjmp Start

	ldi R26 , 0b00111000
	out _PORTB, R26;
	ldi R23, 0xFF ;Устанавливаем величину задержки
	rcall delayx ;Вызов нашей функции задержки
	ldi R26 , 0b00110100 
	out _PORTB, R26;
	ldi R23, 0xFF
	rcall delayx
	ldi R26 , 0b00101100
	out _PORTB, R26;
	ldi R23, 0xFF
	rcall delayx
	ldi R26 , 0b00011100 
	out _PORTB, R26;
	ldi R23, 0xFF
	rcall delayx

	rjmp m1 ;Зацикливаем
	ret

delayx:
	push R26 ;В стеке сохраняем значение R26
n1:
	ldi R26, 0xFF
n2:
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
	brne n2
	dec R27
	brne n1
	pop R26 ;В стеке сохраняем значение R26
	ret