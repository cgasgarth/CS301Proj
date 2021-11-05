slt $at, $s1, $s0 #sgt
beq $at, $zero, GE1
j LTEQ1
GE1:beq $s1, $s2, LTEQ1
addi $s2, $zero, 1
j end1
LTEQ1:addi $s2, $zero, 0
end1:slt $at, $s1, $s0 #sge
beq $at, $zero, GTEQ2
addi $s2, $zero, 0
j end2
GTEQ2:addi $s2, $zero, 1
end2:slt $at, $s1, $s0 # sle $s2, $s1, $s0
beq $at, $zero, GTEQ3
addi $s2, $zero, 1
j end3
GTEQ3:beq $s1, $s0, EQ3
addi $s2, $zero, 0
j end3
EQ3:addi $s2, $zero, 1
end3:sub $at, $s1, $s0 # seq $s2, $s1, $s0
beq $at, $zero, EQ4
addi $s2, $zero, 0
j end4
EQ4:addi $s2, $zero, 1
end4:sub $at, $s1, $s0 # sne $s2, $s1, $s0
beq $at, $zero, EQ5
addi $s2, $zero, 1
j end5
EQ5:addi $s2, $zero, 0
end5:addi $s0, $zero, 10 # li $s0, 10
slt $at, $s0, $s1 # bge $s0, $s1, label
beq $at, $zero, label1
slt $at, $s1, $s0 # bgt $s0, $s1, label
bne $at, $zero, label2
slt $at, $s1, $s0 # ble $s0, $s1, label
beq $at, $zero, label3
slt $at, $s0, $s1 # blt $s0, $s1, label
bne $at, $zero, label4