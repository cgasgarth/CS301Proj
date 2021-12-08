    .text #everything after "text" is your actual code
	  .align 2 #directive that aligns all labels in memory, ignore this for now
    .globl main #Speficies that "main" is the starting label for this program
main:
  addi $a0, $zero, 2  #Setting values to pass to f
  addi $a1, $zero, 4
  addi $a2, $zero, 5
  jal f
  add $s0, $zero, $v0 #a = return of j
  sw $s0, 0($zero)
  # addi $a0, $zero, 10  #Setting values to pass to f
  # addi $a1, $zero, 100 
  # addi $a2, $zero, 500 
  # jal f
  # add $s1, $zero, $v0 #b = return of j
  # addi $a0, $zero, 20  
  # addi $a1, $zero, 392 
  # addi $a2, $zero, 859 
  # jal f
  # add $s2, $zero, $v0 #c = return of j
  j end1

end:
  li $v0, 10 #These two lines cause QTSPIM to not error when your program ends
  syscall #Don't worry about them now, we'll understand what they do later.

end1:
  j end1
    
    
f: 
# int f(int a, int b, int c) {
#         int s = 0;
#         for (int i = a ; i < b ; i++) {
#           for (int j = i ; j < c ; j++) {
#             s += g(i,j);
#           }
#         }
#         return s;
#       }
  addi $sp, $sp, -32 #lower $sp to hold 5 variables
  sw $ra, 0($sp)  #save the values in registers that we will change
  sw $s0, 4($sp)  #int a/i
  sw $s1, 8($sp)  #int b
  sw $s2, 12($sp) #int c
  sw $s3, 16($sp) #loop 1 conditional
  sw $s4, 20($sp) #loop 2 conditional
  sw $s5, 24($sp) #j = i
  sw $s6, 28($sp) #s count

  add $s0, $zero, $a0 #save a registers to s registers
  add $s1, $zero, $a1
  add $s2, $zero, $a2

loopstart1:
  slt $s3, $s0, $s1   #t1 is T if $s0(i) < $s1(b) (and we keep going)
  beq $s3, $zero, loopend1
  add $s5, $zero, $s0 #j = i
    	#inside first loop
  loopstart2:
    slt $s4, $s5, $s2   #s4 is T if $s5(j) < $s2(c) (and we keep going)
    beq $s4, $zero, loopend2
    add $a0, $zero, $s0 #set arguments for g
    add $a1, $zero, $s5
    jal g
    add $s6, $s6, $v0 #s += g(i, j)
    addi $s5, $s5, 1 #$s5(j)++
    j loopstart2
  loopend2:
  addi $s0, $s0, 1 #s0(i)++
  j loopstart1

loopend1:
  add $v0, $zero, $s6 #return s
  lw $ra, 0($sp)  #save the values in registers that we will change
  lw $s0, 4($sp)
  lw $s1, 8($sp)
  lw $s2, 12($sp)
  lw $s3, 16($sp) 
  lw $s4, 20($sp) 
  sw $s5, 24($sp)
  lw $s6, 28($sp)
  addi $sp, $sp, 32 #restore stack pointer
  jr $ra

# int g(int a, int b) {
#         return a + b + 4;
#       }
g:
  add $t0, $a0, $a1
  addi $t0, $t0, 4
  add $v0, $zero, $t0
  jr $ra
