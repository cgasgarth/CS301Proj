slt $at, $s1, $s0
beq $at, $zero, GE 
j LTEQ
GE:
beq $s1, $s2, LTEQ
addi $s2, $zero, 1
j end
LTEQ:
addi $s2, $zero, 0
end: