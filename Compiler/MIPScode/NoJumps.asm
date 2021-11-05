li $s0, 10
start:
addi $s0, $s0, -1
sw $s0, 0($sp)
addi $sp, $sp, 4
bne $s0, $zero, start
end:
j end