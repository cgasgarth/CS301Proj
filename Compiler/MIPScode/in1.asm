          .data
A:        .word 5 2 3


	        .text #everything after "text" is your actual code
	        .align 2 #directive that aligns all labels in memory, ignore this for now
	        .globl main #Speficies that "main" is the starting label for this program

main:
  add $a0, $v1, $zero #comment
  addi $a0, $v1, 10 #comment
  sub $a0, $v1, $zero #comment
  mult $a0, $v1 #comment
  div $a0, $v1 #comment
  mflo $t0 
  mfhi $t1 #coasdfasdf a sdfasdf
  sll $13, $23, 15
  srl $11, $15, 2 
  lw $t3, 2($a0)
  sw $t4, 4($a0)
  slt $2, $5, $a2
  beq $4, $s0, label
  bne $s5, $a0, label2
  j label3
  jal func1
  jr $ra
  jalr $s0, $s1
  syscall

  label:

  label2:
  label3:
  func1: