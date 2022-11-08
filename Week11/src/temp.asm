.data

prompt:  .asciiz     "\nEnter the current temperature:\n"
hot:     .asciiz     "hot\n"
cold:    .asciiz     "cold\n"

.text
# prompt the current temp
li $v0, 4
la $a0, prompt
syscall

# read the current temp
li $v0, 5
syscall
move $t0, $v0

li $t1, 65
# branch to different operations
main:
  bge $t0,$t1,rule1
  beq $t0,$t1,rule1
  ble $t0,$t1,rule2
rule1:
  li $v0, 4
  la $a0, hot
  syscall
  j exit
rule2:
  li $v0, 4
  la $a0, cold
  syscall
  j exit
exit:
  li $v0, 10
	syscall