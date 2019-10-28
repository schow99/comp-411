.text

#.globl nchoosek

NchooseK:

  beq $a0, $0, one #if n equals 0 
  beq $a1, $0, one #if k equals 0 
  beq $a0, $a1, one #if n equals k
  
  addi $sp, $sp, -8 #make room on stack for 2 ints
  sw $ra, 4($sp) 
  sw $fp, 0($sp)
  
  addi $sp, $sp, -8 
  addi $fp, $sp, 12
  
  sw $a0, -8($fp)
  sw $a1, -12($fp)
  
  subi $a0, $a0, 1 #n - 1 
  subi $a1, $a1, 1 #k - 1

  jal NchooseK  #recursion
  
  lw $a0, -8($fp)
  lw $a1, -12($fp)
  sw $v0, -8($fp) #stores result of NchooseK(n-1, k-1)
  addi $sp, $sp, 4 
  
  subi $a0, $a0, 1 #n - 1
  
  jal NchooseK #recursion
  
  lw $t1, -8($fp) #loading result of NchooseK(n-1, k-1)
  add $v0, $v0, $t1 #adding results together
  
  addi $sp, $sp, 4
  
exit:
  lw $ra, 0($fp)
  lw $fp, -4($fp)
  addi	$sp, $sp, 8
  jr $ra  

one: 
  addi $v0, $0, 1 #stores number 1 in return register 
  jr $ra
