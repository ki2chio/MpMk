#ifndef _ASMROUTINE_
#define _ASMROUTINE_
//Общие определения
#ifdef __ASSEMBLER__
//Определения только для ассемблера
//Адрес регистра управления порта B
.equ _DDRB, 0x04
//Адрес регистра данных порта B
.equ _PORTB, 0x05
//Адрес регистра управления порта F
.equ _DDRF, 0x010
//Адрес регистра данных порта F
.equ _PORTF, 0x11
//Адрес регистра входных данных порта F
.equ _PINF, 0x0F
//Адрес регистра управления порта C
.equ _DDRC, 0x07
//Адрес регистра данных порта C
.equ _PORTC, 0x08
//Адрес регистра входных данных порта C
.equ _PINC, 0x06
#endif
#ifndef __ASSEMBLER__
//Определения только для С
extern "C" {
void key_change();
}
#endif
#endif