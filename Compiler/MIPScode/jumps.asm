main:
  addi $a0, $zero, 7
  jal f
  add $s0, $zero, $v0 #s0(a) = f(int)
  sw $s0, 0($zero)
  j end
end:
  j end
  li $v0, 10 #These two lines cause QTSPIM to not error when your program ends
  syscall #Don't worry about them now, we'll understand what they do later.
f:
  addi $sp, $sp, -20
  sw $ra, 0($sp) #save $ra
  sw $s0, 4($sp) #save $s0
  sw $s1, 8($sp) #save $s1, result 
  sw $s2, 12($sp) #save $s2, i
  sw $s3, 16($sp) #s3
  add $s0, $zero, $a0
  bne $s0, $zero, notEqual #jump to notEqual if a != 0
  addi $v0, $zero, 1 #return 1
  j returnf
  notEqual:
  add $s1, $zero, $zero #result = 0
  add $s2, $zero, $zero #i = 0
  loopstart:
    slt $s3, $s2, $s0   #s3 is T if $s2(i) < $s0(a) (and we keep going)
    beq $s3, $zero, loopend
    add $a0, $zero, $s2 #a0 = s2(i)
    jal f
    add $s1, $s1, $v0 #result += f(s2)
    addi $s2, $s2, 1 #i++
    j loopstart
  loopend:
  add $v0, $zero, $s1 #save result to return
  j returnf
  returnf:
    lw $ra, 0($sp) #load $ra
    lw $s0, 4($sp) #load s0
    lw $s1, 8($sp) #save s1
    lw $s2, 12($sp) #load s2
    lw $s3, 16($sp) #save $s2, i
    addi $sp, $sp, 20 #restore $sp
    jr $ra