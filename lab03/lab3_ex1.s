.data                   # where static data is stored.
.word 2, 4, 6, 8        # static data
n: .word 9              # global variable n

.text
main:   add     t0, x0, x0
        addi    t1, x0, 1
        la      t3, n
        lw      t3, 0(t3)
fib:    beq     t3, x0, finish
        add     t2, t1, t0
        mv      t0, t1
        mv      t1, t2
        addi    t3, t3, -1
        j       fib
finish: addi    a0, x0, 1
        addi    a1, t0, 0
        ecall # print integer ecall
        addi    a0, x0, 10
        ecall # terminate ecall

# output number: 34
# address of n: 0x10000010
# calculating the 13th fib: modify x28 to 0x0000000D
