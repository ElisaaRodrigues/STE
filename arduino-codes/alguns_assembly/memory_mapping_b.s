ldi r16, 4
mov r1, r16
subi r16, 3
in r0, 0x3F
out 0x3F, r1
