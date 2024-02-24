// ARMv7-M assembly example
// This example demonstrates how to use
// the ARMv7-M assembly language to add 
// two numbers and return the result.
.global _start

_start:
    mov r1, #5
    mov r2, #6
    b mylabel

result:
    mov r0, r4
    b _exit

mylabel:
    add r4, r1, r2
    b result

_exit:
    mov r7, #0
    svc #0

// clang --target=armv7m -fuse-ld=lld example.s -nostdlib
// as -target armv7m  example.s -o example.o

