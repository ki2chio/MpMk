#ifndef _ASMROUTINE_
#define _ASMROUTINE_
//Общие определения
#ifdef __ASSEMBLER__
//Определения только для ассемблера
.equ MYDEFINE, 10 // Аналог #define в С
#endif
#ifndef __ASSEMBLER__
//Определения только для С
extern "C" {
char asm_func(char * addr);
}
#endif
#endif