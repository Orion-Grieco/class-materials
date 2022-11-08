.data
myMessage: .asciiz "Hello CS-200 MIPS Compiler.\n"
.text
la $a0, myMessage
li $v0, 4
syscall
