# Find Size of the String.
.data
    msg: .asciiz "MIPS is Awesome!"
    nl: .asciiz "\n"
.text
    la $t0, msg
    loop:
        la $t1, 0($t0)
        lb $t2, 0($t0)
        bne $t2, $zero, notequal
        move $a0, $t3
        li $v0, 1
        syscall
        # exit
        li $v0, 10
        syscall
    notequal:
        addi $t0, $t0, 1
        # adding one to the t3 block
        addi $t3, $t3, 1    
        j loop