// simple program that defines
// a integer variable
// and adds four to it
  .syntax unified
	.cpu cortex-m4
	.fpu softvfp
	.thumb
.global _start
_start:
.word 0x0001000
.word led
//.word reset
.word loop
.word loop
.word loop
.space 0x110//calculate
led:
mov r1, #2
mov r2, #5
//.thumb
loop: 
    b loop
/* 
.thumb_func
reset:
    .section	.text.Reset_Handler
	.weak	Reset_Handler
	.type	Reset_Handler, %function
Reset_Handler:
  ldr   sp, =_estack    
    b.
//.global Reset_Handler
//Reset_Handler:
    .section	.text.Default_Handler//,"ax",%progbits
Default_Handler:
Infinite_Loop:
	b	Infinite_Loop

//.global _start
//_start:
Led:
    mov r1, #2
*/

// as -target armv7m -o example.o example.s
// /opt/homebrew/Cellar/llvm/17.0.6_1/bin/ld.lld -T example.ld -o example.elf example.o
// objcopy -O binary example.o example.bin
// qemu-system-arm -M vexpress-a9 -serial stdio -device loader,file=u-boot.bin,addr=0x60800000,cpu-num=0,force-raw=on
// qemu-system-arm -M netduinoplus2 -cpu cortex-m4 -nographic -serial mon:stdio -device loader,file=example.bin,addr=0x00000000,force-raw=on