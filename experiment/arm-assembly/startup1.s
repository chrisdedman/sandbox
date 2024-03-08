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

/* 
 * Commands to run to assembly, link and run this sim
 * as -target armv7m  startup.s -o startup.o
 * /opt/homebrew/Cellar/llvm/17.0.6_1/bin/ld.lld -T test.ld startup.o -o test.elf  
 * /opt/homebrew/Cellar/llvm/17.0.6_1/bin/llvm-objcopy -O binary test.elf test.bin
 * qemu-system-arm -M netduinoplus2 -m 128M -nographic -s -S -kernel test.bin

 * Option explained:
        -s  shorthand for -gdb tcp::1234
        -S  freeze CPU at startup (use 'c' to start execution)
        -m  [size=]megs[,slots=n,maxmem=size]
                configure guest RAM
                size: initial amount of guest memory
                slots: number of hotplug slots (default: none)
                maxmem: maximum amount of guest memory (default: none)
                Note: Some architectures might enforce a specific granularity
 */