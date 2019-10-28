
.data
  AA:     .space 400  		# int AA[100]
  BB:     .space 400  		# int BB[100]
  CC:     .space 400  		# int CC[100]
  m:      .space 4   		# m is an int whose value is at most 10
                     		# actual size of the above matrices is mxm
  test:  .asciiz "Testing"  
  newLine: .asciiz "\n"
  space: .asciiz " "
                 	

      # Yousciiz  may add more variables here if you need to



.text


main:
  

#------- INSERT YOUR CODE HERE for main -------
#
#  Best is to convert the C program line by line
#    into its assembly equivalent.  Carefully review
#    the coding templates near the end of Lecture 8.
#
#
#  1.  First, read m (the matrices will then be size mxm).

#enter value for m
  li $v0, 5 
  syscall
  
  move $t0, $v0 #store value of m in $t0
  
  li $t1, 11 #load 10 into t1
  slt $s0, $t0, $t1 #if m is less than 11
  beq $s0, $zero, returnZero 
  

  
  
#  2.  Next, read matrix A followed by matrix B.
    li, $t2, 0 #beginning of loop, index treated as i 
    loop1: 
      beq $t2, $t0, endloop1
      
      li $t3, 0 #beginning of second loop, index treated as j 
      loop2: 
      	beq $t3, $t0, endloop2

      	
      	li $v0, 5  #user input for value	
  	syscall
  		
  	mul $t4, $t2, $t0 #map to linearized index
  	add $t5, $t4, $t3 #continue mapping to index
  	addi $t6, $0, 4 #store 4 in $t6
  	mul $t7, $t6, $t5 #offset
  	
  	sw $v0, AA($t7)
  	
       	addi $t3, $t3, 1 #increment 
       	
      	j loop2 #loops back around
      endloop2: 
      	addi $t2, $t2, 1
      	j loop1
      endloop1: 
    
    
    
    li, $t2, 0 #beginning of loop, index treated as i 
    loopB1: 
      beq $t2, $t0, endloopB1
      
      li $t3, 0 #beginning of second loop, index treated as j 
      loopB2: 
      	beq $t3, $t0, endloopB2

      	
      	li $v0, 5  #user input for value	
  	syscall
  	
  	mul $t4, $t2, $t0 #map to linearized index
  	add $t5, $t4, $t3 #continue mapping to index
  	addi $t6, $0, 4 #store 4 in $t6
  	mul $t7, $t6, $t5 #offset
  	
  	sw $v0, BB($t7)
  	
  #	lw $t6, AA($t7)
  	
  #	li $v0, 1
  #	add $a0, $t6, $0
  #	syscall
  	
      	addi $t3, $t3, 1 #increment 
      	  	
      	j loopB2 #loops back around
      endloopB2: 
      	addi $t2, $t2, 1
      	j loopB1
      endloopB1: 
    
   

#  3.  Compute matrix product.  You will need triple-nested loops for this.
    li, $t2, 0 #beginning of loop, index treated as i 
    
  #  addi $a1, $0, 4 #store value of 4 
    
    loopC1: 
      beq $t2, $t0, endloopC1
      
      li $t3, 0 #beginning of second loop, index treated as j 
      loopC2: 
      	beq $t3, $t0, endloopC2
      	
      	li $t4, 0 #treat as k 
      	loopC3: 
      	  beq $t4, $t0, endLoopC3
      	  
      	  mul $t5, $t2, $t0 #i*m is stored in t5
      	  add $t5, $t5, $t3 #i*m+j 
      	  sll $t5, $t5, 2 #offset
      	  
      	  mul $t6, $t2, $t0 #i*m
      	  add $t6, $t6, $t4 #i*m +k
   	  sll $t6, $t6, 2 #offset
      	  
      	  mul $t7, $t4, $t0 #k*m
      	  add $t7, $t7, $t3 #k*m+j
	  sll $t7, $t7, 2 #offset
	  
	  lw $a2, AA($t6) #accessing value for AA matrix 
	  lw $a3, BB($t7) #accessing value for BB matrix
	  lw $a1, CC($t5) #accessing value for CC matrix 
	 	  
	  
	  mul $t8, $a3, $a2 #value to go in matrix 
	  add $t8, $t8, $a1
	  
#	  li $v0, 1
 #  	  add $a0, $t8, $0
 #     	  syscall
      	  
 #     	  li $v0, 4
#      	la $a0, space
 #     	syscall
	  
	  
	  sw $t8, CC($t5)

      	  addi $t4, $t4, 1 #increment 
      	  j loopC3 #loop back 
      	  
      	endLoopC3:
      	  addi $t3, $t3, 1 #increment
      	  j loopC2
      	      	
      endloopC2: 
      	addi $t2, $t2, 1 #increment
      	j loopC1
      endloopC1:


#  4.  Print the result, one row per line, with one (or more) space(s) between
#      values within a row.

    li, $t2, 0 #beginning of loop, index treated as i 
    printLoop1: 
      beq $t2, $t0, endPrintLoop1
      
      li $t3, 0 #beginning of second loop, index treated as j 
      printLoop2: 
      	beq $t3, $t0, endPrintLoop2

      	

  	mul $t4, $t2, $t0 #map to linearized index
  	add $t5, $t4, $t3 #continue mapping to index

  	sll $t7, $t5, 2 #offset
  	
  	lw $t1, CC($t7)
  	
  	li $v0, 1
      	add $a0, $t1, $0
      	syscall
      	
      	li $v0, 4
      	la $a0, space
      	syscall
      	
    #  	li $v0, 4
    #    la $a0, test
    #    syscall
  	
  	addi $t3, $t3, 1 #increment 
  	      	
      	j printLoop2 #loops back around
      endPrintLoop2: 
       	li $v0, 4
      	la $a0, newLine
      	syscall
      	addi $t2, $t2, 1
      	j printLoop1
      endPrintLoop1:





#  5.  Exit.
#
#------------ END CODE ---------------


exit:                     # this is code to terminate the program -- don't mess with this!
  addi $v0, $0, 10      	# system call code 10 for exit
  syscall               	# exit the program



returnZero: 
  addi $s0, $zero, 0
  add $v0, $s0, $s0
  
  li $v0, 4
  la $a0, test
  syscall 
  
  j exit
 



    addi $t4, $0, 0 #initialize while loop with $t4 as counter
    mul $t1, $t0, $t0 #m*m
    mul $t1, $t1, $t4 #4*m*m to calculate offset
    

    while: 
      beq $t4, $t1, exit
      lw $t6, CC($t4)
      
      addi $t4, $t4, 4
      
      li $v0, 1
      move $a0, $t6
      syscall
      
      	  
      li $v0, 4
      la $a0, test
      syscall
      j while 



#------- If you decide to make other functions, place their code here -------
#
#  You do not have to use helper methods, but you may if you would like to.
#  If you do use them, be sure to do all the proper stack management.
#  For this exercise though, it is easy enough to write all your code
#  within main.
#
#------------ END CODE ---------------

