.data

prompt:  .asciiz     "\nEnter the current temperature:\n"
hot:     .asciiz     "hot\n"
mild:     .asciiz     "mild\n"
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
li $t2, 50
# branch to different operations
main:
  bge $t0,$t1,rule1
  blt $t0,$t1,rule2a
rule1:
  li $v0, 4
  la $a0, hot
  syscall
  j exit
rule2a:
  bge $t0, $t2, rule2b
  blt $t0,$t2,rule3
rule2b:
  li $v0, 4
  la $a0, mild
  syscall
  j exit
rule3:
  li $v0, 4
  la $a0, cold
  syscall
  j exit
exit:
  li $v0, 10
	syscall