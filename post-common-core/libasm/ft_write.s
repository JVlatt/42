.intel_syntax noprefix

.section .text
.globl ft_write
.extern __errno_location

ft_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jge success

    neg rax
    mov rdi, rax
    call __errno_location
    mov [rax], rdi
    mov rax, -1
    ret

success:
    ret

