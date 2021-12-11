syscall:
beq $v0, $zero, main
li $at, 1
beq $v0, $at, syscall1 #syscall1
li $at, 5
beq $v0, $at, syscall5 #syscall5
li $at, 9
beq $v0, $at, syscall9 #syscall9
li $at, 11
beq $v0, $at, syscall11 #syscall11
li $at, 12
beq $v0, $at, syscall12 #syscall12
jr $k0
syscall1:

jr $k0
syscall5:

jr $k0
syscall9:
add $k1, $a0, $k1
add $v0, $k1, $zero #heap moves up when memory is allocated
jr $k0              #access allocated mem by v0 - space allocated
syscall11: #printing to terminal
addi $at, $zero, 32
sw $a0, 0($at)
jr $k0
syscall12:
addi $at, $zero, 16
syscall12Start:
addi $v0, $zero, 0
lw $v0, 0($at) #load value from keyboard controller
beq $v0, $zero, syscall12Start
jr $k0
main:
addi $v0, $zero, 12
jalr $zero, $k0

add $a0, $zero, $v0
addi $v0, $zero, 11
jalr $zero, $k0
j main