  beq $4, $s0, label
  bne $s5, $a0, label2
  j label3
  jal func1
  label1:
  label2:
  label3:
  func1: