.text
.globl main
main: 
addi $t0, $zero, 5 #comment
#comment
addi $s0, $zero, 0
loop:
add $s0, $s0, $t0
addi $t0, $t0, -1
bne $t0, $zero, loop