#include "asmroutine.h"
;Экспортируем asm_func
.global asm_func
;Реализуем функцию
asm_func:
; Параметр будет находиться в R25:R24 (адрес переменной)
; Переносим значение в указатель X
ldi R20, 0
mov R26, R24
mov R27, R25
; Загружаем значение из памяти
M2:
ld R24, X+
add R20, R24
dec R22
brne M2
mov R24, R20
ret
