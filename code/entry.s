
.extern cmain
.section .text.init
_start:
    li sp, 0x2000
    /*j cmain*/
#     li a3, 2 /* base */
#     li a4, 3 /* exp */
#     li a5, 1 /* result = 1 */

# _loop:
#     blez a4, _endloop
#     addi a4, a4, -1
#     mv a0, a5
#     mv a1, a3
#     jal ra, _mult_loop
# _endloop:

# _mult_loop:
#     blez a1, _end_mult_loop
#     addi a1, a1, -1
#     add a2, a2, a0
#     j _mult_loop
# _end_mult_loop:
#     jr _loop

#     mv a0, a2
    j cmain
_here:
    j _here
