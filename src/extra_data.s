.include "macro.inc"

.section .data, "a"

/* declared for N64Recomp reasons. */

nonmatching extra_data

dlabel extra_data
    .word 0xDEADBEEF
    .word 0xDEADBEEF
    .word 0xDEADBEEF
    .word 0xDEADBEEF
enddlabel extra_data
