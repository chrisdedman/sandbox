SECTIONS {
         . = 0x00001000;
         .text : { * (.text); }

         . = 0x00001400;
         .data : { * (.data); }
}