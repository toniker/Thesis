MOV    r1, #0                        ; Initialize segment counter outer_loop
MOV    r0, #0                        ; Initialize line counter inner_loop
ORR    r2, r1, r0                    ; Generate segment and line address
MCR    p15, 0, r2, c7, c14, 2        ; Clean and flush the line
ADD    r0, r0, #0x20                 ; Increment to next line
CMP    r0, #0x400                    ; Complete all entries in one segment?
BNE    inner_loop                    ; If not branch back to inner_loop
ADD    r1, r1, #0x40000000           ; Increment segment counter
CMP    r1, #0x0                      ; Complete all segments
BNE    outer_loop                    ; If not branch back to outer_loop
                                     ; End of routine