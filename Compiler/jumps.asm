  jlab:
  jallab:
  beqlab:
  bnelab:
  beq $4, $s0, beqlab
  bne $s5, $a0, bnelab
  j jlab
  jal jallab