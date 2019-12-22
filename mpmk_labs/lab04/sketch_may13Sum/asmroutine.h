#ifndef _ASMROUTINE_
#define _ASMROUTINE_
//Общие определения
#ifdef __ASSEMBLER__
//Определения только для ассемблера
#endif
#ifndef __ASSEMBLER__
//Определения только для С
extern "C" {
  char asm_func(char * addr, char num);
}
#endif
#endif
