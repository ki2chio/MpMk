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
	;Используем две кнопки

	cbi _DDRC, 1 ;Настраиваем на ввод информации 1 бит порта C
	cbi _DDRC, 2 ;Настраиваем на ввод информации 2 бит порта C
	sbi _PORTC, 1 ;Подаем логическую "1" на 1 бит порта C
	sbi _PORTC, 2 ;Подаем логическую "1" на 2 бит порта C
	ldi R26 , 0b00111111;
	rjmp metka

Down:
	lsl R26
	out _PORTB, R26
	ldi R23, 0xFF ;Устанавливаем величину задержки
	rcall delayx ;Вызов нашей функции задержки
	rjmp metka
Up:
	lsr R26 
	out _PORTB, R26
	ldi R23, 0xFF ;Устанавливаем величину задержки
	rcall delayx ;Вызов нашей функции задержки
	rjmp metka

metka:
	
	nop
	sbis _PINC, 1
	rjmp Down
	nop

	nop
	sbis _PINC, 2
	rjmp Up
	nop

rjmp metka ;Зацикливаем
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