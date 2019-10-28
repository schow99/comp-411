# =============================================================
# main PROCEDURE TEMPLATE # 4b
#
# Use with "proc_template4b.asm" as the template for other procedures
#
# Based on Slide 37 of Lecture 9 (Procedures and Stacks)
#   (main is simpler than other procedures because it does not have to
#     clean up anything before exiting)
#
# Assumptions:
#
#   - main calls other procedures with no more than 4 arguments ($a0-$a3)
#   - any local variables needed are put into registers (not memory)
#   - no values are put in temporaries that must be preserved across a call from main
#       to another procedure
#
# =============================================================

.data 0x0
#
# declare global variables here
	newLine: .asciiz "\n"

.text 0x3000
.globl main

main:

    ori     $sp, $0, 0x3000     # Initialize stack pointer to the top word below .text
                                # The first value on stack will actually go at 0x2ffc
                                #   because $sp is decremented first.
    addi    $fp, $sp, -4        # Set $fp to the start of main's stack frame



    # =============================================================
    # No need to create room for temporaries to be protected.
    # =============================================================




    # =============================================================
    # BODY OF main
    # ...
    # ...
    # ...
    # ... CODE FOR main HERE
        
            # =====================================================
            # main CALLS proc1
            #
            # Suppose main needs to call proc1, but there are no
            #   temporaries that need to be protected for this call.
            #
            # Suppose there are four arguments to send to proc1:
            #   (0, 10, 20, 30).  Here's how to do it.


	
	li $v0, 5 #value for n
 	syscall
  	
        or $a0, $0, $v0     # Put n in $a0
        
        beq $a0, $0, exit_from_main
        
        li $v0, 5 #value for k
 	syscall
            
        or $a1, $0, $v0     # Put j in $a1

	jal nchoosek
	
	add $a0, $v0, $0
      	ori $v0, $0, 1
      	syscall
	
	#j exit_from_main
	
	li $v0, 4
      	la $a0, newLine
      	syscall
	
	j main
	

     #       jal     proc1           # call proc1
                                    # valued returned by proc1 will be in $v0-$v1

            # =====================================================
            

    # ... MORE CODE FOR main HERE
    # ...
    # ...
    # END OF BODY OF main
    # =============================================================
nchoosek:	
	beq $a0, $0, return_one
	beq $a1, $0, return_one
	beq $a0, $a1, return_one
	
	subi $sp, $sp, 8 #make room for 2 integers
	sw $fp, ($sp) #store value of return address to stack 
	sw $ra, 4($sp)
	
	addi $fp, $sp, 4
	addi $sp, $sp, -8
	
	sw $a0, -8($fp)
	sw $a1, -12($fp)
	
	subi $a0, $a0, 1
	subi $a1, $a1, 1
	
	jal nchoosek

	lw $a0, -8($fp)
	lw $a1, -12($fp)
	sw $v0, -8($fp)	
	
	addi $sp, $sp, 4
	subi $a0, $a0, 1
	
	jal nchoosek
	
	lw $t0, -8($fp)
	add $v0, $v0, $t0
	addi $sp, $sp, 4

	
restore:
	lw $ra, 0($fp)
	lw $fp, -4($fp)
	addiu $sp, $sp, 8
	jr $ra
		
return_one:
	addi $v0, $zero, 1
	jr $ra

exit_from_main:
    ori $v0, $0, 10     # System call code 10 for exit
    syscall                 # Exit the program
end_of_main:
