.section .data
msg:
    .ascii "hello, world!\n"
    len=.-msg

.section .text
.global _start
_start:
    movl $len, %edx
    movl $msg, %ecx
    movl $0x1, %ebx
    movl $0x4,%eax
    int $0x80

_exit:
    movl $0x0,%ebx
    movl $0x1,%eax
    int $0x80
    hlt
