SECTIONS
{
  . = 0x0;
  .raw : { 
      KEEP(*(.text.init))
      *(.text .bss .data .rodata)
    }
}