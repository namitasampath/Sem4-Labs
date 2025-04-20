    AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x20001000         ; Stack pointer address (valid RAM region)
    DCD Reset_Handler

    ALIGN
    AREA mycode, CODE, READONLY
    ENTRY
    EXPORT Reset_Handler

Reset_Handler
    LDR r0, =number1       ; r0 -> number1 (64-bit)
    LDR r1, =number2       ; r1 -> number2 (64-bit)
    LDR r2, =result        ; r2 -> result array (128-bit)

    ; Load 64-bit number1
    LDR r3, [r0], #4       ; r3 = number1 low 32 bits
    LDR r4, [r0]           ; r4 = number1 high 32 bits

    ; Load 64-bit number2
    LDR r5, [r1], #4       ; r5 = number2 low 32 bits
    LDR r6, [r1]           ; r6 = number2 high 32 bits

    ; Step 1: A_lo * B_lo
    UMULL r7, r8, r3, r5   ; r7 = low, r8 = high

    ; Step 2: A_lo * B_hi
    UMULL r9, r10, r3, r6

    ; Step 3: A_hi * B_lo
    UMULL r11, r12, r4, r5

    ; Add cross products to middle
    ADDS r8, r8, r9        ; lower half addition
    ADCS r10, r10, r12     ; upper with carry

    ; Step 4: A_hi * B_hi
    UMULL r9, r12, r4, r6
    ADDS r10, r10, r9      ; add low
    ADC  r12, r12, #0      ; add carry to high

    ; Store result: 128-bit = r7 (lo), r8, r10, r12 (hi)
    STR r7, [r2], #4
    STR r8, [r2], #4
    STR r10, [r2], #4
    STR r12, [r2]

STOP
    B STOP

number1 DCD 0x89ABCDEF, 0x12345678   ; number1 = 0x1234567889ABCDEF
number2 DCD 0x01234567, 0x0FEDCBA9   ; number2 = 0x0FEDCBA901234567

    AREA mydata, DATA, READWRITE
result  DCD 0, 0, 0, 0               ; 128-bit result (4 words)

    END
