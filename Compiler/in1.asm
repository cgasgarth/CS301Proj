          .data
A:        .word 5 2 3


	        .text #everything after "text" is your actual code
	        .align 2 #directive that aligns all labels in memory, ignore this for now
	        .globl main #Speficies that "main" is the starting label for this program

main:
  la $s0, A 
  lw $s1, 0($s0) #Loads A[0]
  lw $s2, 4($s0) #Loads A[1]
  slt $s3, $s1, $s2
  beq $s3, $zero, false #Means A[0] is smaller
  addi $s4, $zero, 5
  sw $s4, 8($s0)
  j true
false:
  addi $s4, $zero, 50
  sw $s4, 8($s0)
true:
  li $v0, 10 #These two lines cause QTSPIM to not error when your program ends
  syscall #Don't worry about them now, we'll understand what they do later.