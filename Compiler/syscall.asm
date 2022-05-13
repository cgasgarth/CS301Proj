syscall:
    beq $v0, $zero, main
    li $at, 1
    beq $v0, $at, syscall1 #syscall1
    li $at, 5
    beq $v0, $at, syscall5 #syscall5
    li $at, 9
    beq $v0, $at, syscall9 #syscall9
    li $at, 10
    beq $v0, $at, syscall10 #syscall9
    li $at, 11
    beq $v0, $at, syscall11 #syscall11
    li $at, 12
    beq $v0, $at, syscall12 #syscall12
    jr $k0

    syscall1:

    jr $k0

    syscall5:
    li $v0, 0
    addi $sp, $zero, -12
    sw $t0, 0($sp) #taking in new numbers to add to $v0
    sw $t1, 4($sp) #used for bounds checks
    sw $t2, 8($sp) #check runs through to set base of 10
    addi $t2, $zero, 1
    startSyscall5:
    addi $at, $zero, 16
    syscall5KL:
    li $t0, 0
    lw $t0, 0($at) #load value from keyboard controller
    beq $t0, $zero, syscall5KL

    li $at, 10 #carraige return to end, "enter"
    beq $at, $t0, endSysCall5

    addi $t0, $t0, -48
    mult $t0, $t2 #multipy by what base of 10 we are on
    mflo $t0
    add $v0, $v0, $t0 
    li $t0, 10
    mult $t2, $t0
    mflo $t2
    j startSyscall5
    endSysCall5:
    lw $t0, 0($sp)
    lw $t1, 4($sp)
    lw $t2, 12($sp)
    addi $sp, $zero, 12
    jr $k0

    syscall9:
    add $k1, $a0, $k1
    add $v0, $k1, $zero #heap moves up when memory is allocated
    jr $k0              #access allocated mem by v0 - space allocated
    syscall10:
    j syscall10
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
    addi $v0, $zero, 5
    syscall
    add $a0, $zero, $v0
    addi $v0, $zero, 11
    syscall
    beq $v0, $zero, main
    li $at, 1
    beq $v0, $at, syscall1 #syscall1
    li $at, 5
    beq $v0, $at, syscall5 #syscall5
    li $at, 9
    beq $v0, $at, syscall9 #syscall9
    li $at, 10
    beq $v0, $at, syscall10 #syscall9
    li $at, 11
    beq $v0, $at, syscall11 #syscall11
    li $at, 12
    beq $v0, $at, syscall12 #syscall12
    jr $k0beq $v0, $zero, main
    li $at, 1