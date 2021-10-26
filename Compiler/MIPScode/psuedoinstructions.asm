# sgt $s2, $s1, $s0
# translates to
slt $at, $s1, $s0
beq $at, $zero, GE1
j LTEQ1
GE1:
beq $s1, $s2, LTEQ1
addi $s2, $zero, 1
j end1
LTEQ1:
addi $s2, $zero, 0
end1:

# sge $s2, $s1, $s0
# translates to
slt $at, $s1, $s0
beq $at, $zero, GTEQ2
addi $s2, $zero, 0
j end2
GTEQ2:
addi $s2, $zero, 1
end2:

# sle $s2, $s1, $s0
# translates to
slt $at, $s1, $s0
beq $at, $zero, GTEQ3
addi $s2, $zero, 1
j end3
GTEQ3:
beq $s1, $s0, EQ3
addi $s2, $zero, 0
j end3
EQ3:
addi $s2, $zero, 1
end3:

# seq $s2, $s1, $s0
# translates to
sub $at, $s1, $s0
beq $at, $zero, EQ4
addi $s2, $zero, 0
j end4
EQ4:
addi $s2, $zero, 1
end4:

# sne $s2, $s1, $s0
# translates to
sub $at, $s1, $s0
beq $at, $zero, EQ5
addi $s2, $zero, 1
j end5
EQ5:
addi $s2, $zero, 0
end5:

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
