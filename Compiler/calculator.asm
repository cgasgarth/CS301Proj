          .data
          .text
          .align 2
          .globl main
#To use this calculator in QTSPIM, load it as is into QTSPIM.
#To use this in your Logisim project, copy your assemply implementation of
#syscall here at the front first
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
  jal printHello
mainloop:
  jal printTypeMath
  addi $v0, $zero, 5
  syscall #read integer 1
  add $a0, $v0, $zero
  #addi $v0, $zero, 12   These lines are not needed for QTSPIM but may
  #syscall               be needed for your logisim code to absorb a newline
  addi $v0, $zero, 12
  syscall #read the operation
  add $t0, $v0, $zero
  addi $v0, $zero, 12
  syscall #read a newline
  addi $v0, $zero, 5
  syscall #read integer 2
  add $a1, $v0, $zero
  #addi $v0, $zero, 12   These lines are not needed for QTSPIM but may
  #syscall               be needed for your logisim code to absorb a newline
addtest:
  addi $t1, $zero, 43
  bne $t0,$t1,subtest
  jal addmethod
  j mainloop
subtest:
  addi $t1, $zero, 55
  bne $t0,$t1,multtest
  jal submethod
  j mainloop
multtest:
  addi $t1, $zero, 42
  bne $t0,$t1,divtest
  jal multmethod
  j mainloop
divtest:
  jal divmethod
  j mainloop
addmethod:
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  add $a0, $a0, $a1
  jal printanswer
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  jr $ra
submethod:
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  sub $a0, $a0, $a1
  jal printanswer
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  jr $ra
multmethod:
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  mult $a0, $a1
  mflo $a0
  jal printanswer
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  jr $ra
divmethod:
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  div $a0, $a1
  mflo $a0
  jal printanswer
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  jr $ra
printanswer:
  addi $v0, $zero, 11
  syscall
  jr $ra
printTypeMath:
  addi $v0, $zero, 11
  addi $a0, $zero, 10 #\n
  syscall
  addi $a0, $zero, 84 #T
  syscall
  addi $a0, $zero, 121 #y
  syscall
  addi $a0, $zero, 112 #p
  syscall
  addi $a0, $zero, 101 #e
  syscall
  addi $a0, $zero, 95 # 
  syscall
  addi $a0, $zero, 109 #m
  syscall
  addi $a0, $zero, 97 #a
  syscall
  addi $a0, $zero, 116 #t
  syscall
  addi $a0, $zero, 104 #h
  syscall
  addi $a0, $zero, 33 #!
  syscall
  addi $a0, $zero, 10 #\n
  syscall
  jr $ra
printHello:
  addi $v0, $zero, 11
  addi $a0, $zero, 72 #h
  syscall
  addi $a0, $zero, 101 #e
  syscall
  addi $a0, $zero, 108 #l
  syscall
  addi $a0, $zero, 108 #l
  syscall
  addi $a0, $zero, 111 #o
  syscall
  addi $a0, $zero, 10 #\n
  syscall
  jr $ra
end:
  addi $v0, $zero, 10
  syscall #End the program

