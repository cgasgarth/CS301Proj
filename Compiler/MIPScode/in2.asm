addi $s1, $zero, 32 # address to write to terminal
addi $s2, $zero, 115 # ascii for s
sw $s2, 0($s1)
j end
end: 
j end