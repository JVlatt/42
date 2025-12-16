.intel_syntax noprefix

.section .text
.extern ft_strlen
.extern ft_strcpy
.extern malloc
.globl ft_strdup

ft_strdup:
	mov rbx, rdi
	call ft_strlen
	add rax, 1
	mov rdi, rax
	call malloc
	test rax, rax
	jne malloc_error
	mov rdi, rax
	mov rsi, rbx
	call ft_strcpy
	ret

