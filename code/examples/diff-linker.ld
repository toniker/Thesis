linker-new --- 1/2 --- Text
38 38 MEMORY
39 39 {
40 40   rom      (rx)  : ORIGIN = 0x00400000, LENGTH = 0x00200000
41 41   ram      (rwx) : ORIGIN = 0x20400000, LENGTH = 0x00060000
.. 42   ram_nocache (rwx) : ORIGIN = 0x2045E000, LENGTH = 0x2000
42 43 }
43 44 
44 45 

linker-new --- 2/2 --- Text
87  88 _stack = .;
88  89 } > ram
89  90 
..  91 /* non cacheable area for CAN */
..  92 .ram_nocache (NOLOAD):
..  93 {
..  94 . = ALIGN(4);
..  95 _s_ram_nocache = .;
..  96 *(.ram_nocache)
..  97 . = ALIGN(4);
..  98 _e_ram_nocache = .;
..  99 } > ram_nocache
.. 100 
90 101 . = ALIGN(4);
91 102 _end = . ;

