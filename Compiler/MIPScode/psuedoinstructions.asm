# sgt $s2, $s1, $s0
# translates to
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

# sge $s2, $s1, $s0
# translates to
slt $at, $s1, $s0
beq $at, $zero, GTEQ
addi $s2, $zero, 0
j end
GTEQ:
addi $s2, $zero, 1
end:

# $sle $s2, $s1, $s0
# translates to
slt $ar, $s1, $s0
beq $ar, $zero, GTEQ
addi $s2, $zero, 1
j end
GTEQ:
beq $s1, $s0, EQ
addi $s2, $zero, 0
j end
EQ:
addi $s2, $zero, 1
end:

# seq $s2, $s1, $s0
# translates to
sub $ar, $s1, $s0
beq $ar, $zero, EQ
addi $s2, $zero, 0
j end
EQ:
addi $s2, $zero, 1
end:

# sne $s2, $s1, $s0
# translates to
sub $ar, $s1, $s0
beq $ar, $zero, EQ
addi $s2, $zero, 1
j end
EQ:
addi $s2, $zero, 0
end:

# li $s0, 10
# translates to
addi $s0, $zero, 10

# bge $s0, $s1, label
# translates to
slt $at, $s0, $s1
beq $at, $zero, label

# bgt $s0, $s1, label
# translates to
slt $at, $s1, $s0
bne $at, $zero, label

# ble $s0, $s1, label
# translates to
slt $at, $s1, $s0
beq $at, $zero, label

# blt $s0, $s1, label
# translates to
slt $at, $s0, $s1
bne $at, $zero, label
