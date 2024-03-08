_estack = 0x00001000;    /* end of RAM */

/* Specify the memory areas */
/*MEMORY
{
FLASH (rx)      : ORIGIN = 0x1000, LENGTH = 1K
}*/

/* Define output sections */
SECTIONS
{
  /* The startup code goes first into FLASH */
  .isr_vector :
  {
    . = ALIGN(8);
    KEEP(*(.isr_vector)) /* Startup code */
    . = ALIGN(8);
  } >FLASH

  /* The program code and other data goes into FLASH */
  .text :
  {
    . = ALIGN(8);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */

    . = ALIGN(8);
    _etext = .;        /* define a global symbols at end of code */
  } >FLASH

  .data : 
  {
    . = ALIGN(8);
    _sdata = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */

    . = ALIGN(8);
    _edata = .;        /* define a global symbol at data end */
  } /*>RAM AT> FLASH*/

}