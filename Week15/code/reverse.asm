# This program prints out the string specified in str, reversed
.data
  str:  .asciiz   "MIPS is awesome!"
.text
  # $t0 holds the string address
  la $t0, str   
  # put backup of the starting address of string into $t3
  la $t3, 0($t0)    
  
  # top of our main loop
  loopTop:        
    # load the character at address $t0
    lb $t2, 0($t0)      
    
    # jump to notEqual if things aren't equal
    bne $t2, $zero, notEqual  
    
    # At this point, the length of our string (16) is stored in $t1, and $t0 is currently pointing off the end of the string
    # step back one character in the string to get back
    subi $t0, $t0, 1
    
  
  # top of the second loop
  topReverseLoop:     
    # print the character in $t0
    lb $a0, ($t0)
    li $v0, 11
    syscall 
    
    # check $t0 is not equal to $t3 (start of the string)
    # if they are not equal branch
    bne $t0, $t3, reverseNotEqual 
    
    # we printed all characters so exit
    j exit 
  reverseNotEqual:
    # backup the pointer stored in $t0 by 1
    # decrements address in $t0
    subi $t0, $t0, 1 
    
    # jump to topReverseLoop
    j topReverseLoop
  notEqual:
    # increment $t1
    addi $t1, $t1, 1    
    
    # move to the next char
    addi $t0, $t0, 1    
    
    # jump to the top of the loop
    j loopTop   
  exit:
    li $v0 10
    syscall