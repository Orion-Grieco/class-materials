.data
break:  .asciiz     "\n"
.text
li $t1, 1
li $t2, 1
li $t3, 5

counter:
    li $v0, 1
    la $a0, 0($t1)
    syscall

    li $v0, 4
    la $a0, break
    syscall

    add $t1,$t1,$t2
    beq $t1,$t3,exit
    j counter
    
exit:
    li $v0, 10
    syscall