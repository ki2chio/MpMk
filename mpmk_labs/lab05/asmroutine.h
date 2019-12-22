#ifndef _ASMROUTINE_
#define _ASMROUTINE_
//Общие определения
#ifdef __ASSEMBLER__
//Определения только для ассемблера
//Адрес регистра управления порта B
.equ _DDRB, 0x04
//Адрес регистра данных порта B
.equ _PORTB, 0x05
#endif
#ifndef __ASSEMBLER__
//Определения только для С
extern "C" {
void led_effect();
}
#endif
#endif