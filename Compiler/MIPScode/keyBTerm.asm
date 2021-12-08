main:
addi $s0, $zero, 32 # address to write to terminal
addi $s1, $zero, 16 # base for keyboard controller
addi $s2, $zero 126
start:
li $v0, 0
lw $v0, 0($s1) #load value from keyboard controller
sw $v0, 0($s0)
beq $v0, $s2, end
j start
end: 
j end