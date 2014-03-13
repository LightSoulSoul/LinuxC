section .text
extern puts
global main

main:
push dword msge;
call puts;
add esp, byte 4;
ret;

msge:
db "Hello World!", 0
