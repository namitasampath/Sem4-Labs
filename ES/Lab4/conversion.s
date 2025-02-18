/*Write an assembly program to convert a 2 digit hexadecimal number into unpacked
ASCII*/
    AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x40001000 ; stack pointer value when stack is empty
    DCD Reset_Handler ; reset vector
    ALIGN
    AREA mycode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    LDR R0,=NUM
    LDR R3,=RESULT
    LDRB R1,[R0] ; load hex number into register R1
    AND R2,R1,#0x0F ; mask upper 4 bits
    CMP R2,#09 ; compare the digit with 09
    BLS DOWN ; if it is lower than 9 then jump to down label
    ADD R2,#07 ;else add 07 to that number
DOWN
    ADD R2,#0x30 ; Add 30H to the number, Ascii value of first digit
    STRB R2,[R3]
    AND R4,R1,#0xF0 ; Mask the second digit
    MOV R4,R4,LSR#04 ; Shift right by 4 bits
    CMP R4,#09 ; check for >9 or not
    BLS DOWN1
    ADD R3,#07
DOWN1
    ADD R4,#0x30 ; Ascii value of second digit
    STRB R4,[R3,#01]
NUM DCD 0x000003A
    AREA data, DATA, READWRITE
RESULT DCD 0
    END
