;Включаем заголовочный файл, на случай, если
;в нем есть какие-либо необходимые определения
#include "asmroutine.h"
;Экспортируем asm_func
.global asm_func_wait_1mks
;Реализуем функцию
asm_func_wait_1mks:
; Переносим значение константы в регистр R25,
 ldi R25, MYDEFINE
; Складываем параметр, который лежит в R24,
; и значение глобальной переменной
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
; Все, больше ничего делать не надо, потому что
; возвращаемое значение и должно лежать в R24,
; выходим из подпрограммы
 ret
 
 .global asm_func_wait_3_4mks
 asm_func_wait_3_4mks:
 ldi R25, MYDEFINE
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 add R24,R25
 ret
 .global asm_func_wait_5mks
 asm_func_wait_5mks:
  PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
PUSH R18
POP R18
  ret
  
