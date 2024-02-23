// simple program that defines
// a integer variable
// and adds four to it

.global _start
_start:
    mov r0, #2

//clang --target=armv7m -fuse-ld=lld example.s -nostdlib