#ifndef _ASMROUTINE_
#define _ASMROUTINE_
//Общие определения
#ifdef __ASSEMBLER__
//Определения только для ассемблера
.equ MYDEFINE, 5 // Аналог #define в С
#endif
#ifndef __ASSEMBLER__
//Определения только для С
extern "C" {
 char asm_func_wait_1mks(char b);
 char asm_func_wait_3_4mks(char b);
 void asm_func_wait_5mks();
}
#endif
#endif
