.data
allowed_chars: .asciiz "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
number: .asciiz "ABCD"
base: .word 16

.text
validate_number:
    la t0, number # Address of number string
    
    la t1, base
    lw t1, 0(t1) # Base of number
validate_number_loop:
    # Get current character
    lbu t2, 0(t0)
    
    # If we're at the null terminator, we've finished
    beqz t2, validate_number_success

    # Prepare for function call
    mv a0, t2
    mv a1, t1
    addi sp, sp, -8
    sw t0, 0(sp)
    sw t1, 4(sp)

    jal ra, validate_number_char
    beqz a0, validate_number_failure

    # Reload from stack
    lw t0, 0(sp)
    lw t1, 4(sp)
    addi sp, sp, 8

    # Go to next character
    addi t0, t0, 1
    j validate_number_loop

validate_number_success:
    addi a0, x0, 1
    j validate_number_exit

validate_number_failure:
    add a0, x0, x0

validate_number_exit:
    # Before this line, you should set a0 to be 1 or 0 depending on the
    # validity of the given number and base.
    # The following block convert 0 -> '0' and 1 -> '1' and prints the
    # character.
    add a1, x0, a0
    addi a1, a1, 48
    addi a0, x0, 11
    ecall

    # Terminate the program
    addi a0, x0, 10
    ecall

validate_number_char:
    # a0 is the character, a1 is the base
    add t0, a0, x0
    addi t1, a1, -1
    la t2, allowed_chars
char_loop:
    blt t1, x0, failure
    add t3, t2, t1
    lb t4, 0(t3)
    beq t0, t4, success
    addi t1 t1 -1
    j char_loop
success:
    addi a0, x0, 1
    j char_exit
failure:
    addi a0, x0, 0
char_exit:
    ret