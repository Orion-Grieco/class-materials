.data
	list:	    		.space	400
	newline:  			.asciiz "\n"
  	promptScore:   	    .asciiz "Enter the student scores:\n"
	promptNum:			.asciiz "Enter the number of students:\n"
	promptAvg:			.asciiz "The Average grade is: "
	promptMin:          .asciiz "The Mininum grade is: "
	promptMax:			.asciiz "The Maximum grade is: "
.text
	li $a1, 0 # size of the array
	li $t0, 0 # first counter to run the store loop
	li $t1, 0 # first size counter
	li $t2, 0 # second counter to run the loop
	li $t3, 0 # second size counter
	li $t5, 0 # store sum and avg
	li $t6, 0 # store min
	li $t9, 0 # store max

	la $a0, promptNum
	li $v0, 4
	syscall

	li $v0, 5
	syscall
	move $a1, $v0
store:
	beq $t0, $a1, loop
	la $a0, promptScore
	li $v0, 4
	syscall
  	li $v0, 5
	syscall
	sw $v0, list($t1)    # store the value into list(i)
	addi $t1, $t1, 4     # increment t1 by 4
	addi $t0, $t0, 1     # increment t0 by 1
	move $t6, $v0
	move $t9, $v0
	j store
loop:
	beq $t3, $a1, final 	# if $t3 == $a1 then go to 							# final
	lw $a0, list($t2) 		# $a0 = list(i)
	add $t5, $t5, $a0			# add list(i) to the sum
	blt $a0, $t6, new_min		# if list(i) < min
	j check_max
new_min:
	move $t6, $a0		# min = list(i)
check_max:
	bgt $a0, $t9, new_max		 # if list(i) > max
	j update_counter
new_max:
	move $t9, $a0		# max = list(i)
update_counter:
	addi $t2, $t2, 4    # Every 4 bytes there is an integer in the array
	addi $t3, $t3, 1    #counter ++
	j loop       		#goto loop
final:
	la $a0, promptMin
	li $v0, 4
	syscall
	li $v0, 1
	move $a0, $t6
	syscall
	la $a0, newline
	li $v0, 4
	syscall
	
	la $a0, promptMax
	li $v0, 4
	syscall
	li $v0, 1
	move $a0, $t9
	syscall
	la $a0, newline
	li $v0, 4
	syscall

	div $t5, $t5, $a1 # calculate mean
	la $a0, promptAvg
	li $v0, 4
	syscall
	li $v0, 1
	move $a0, $t5
	syscall

	li $v0, 10
	syscall