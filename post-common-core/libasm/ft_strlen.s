.intel_syntax noprefix

.section .text
.globl ft_strlen

ft_strlen:
	mov rcx, 0
	jmp count_loop

count_loop:
	mov al, [rdi]
	cmp al, 0
	je end

	inc rcx
	inc rdi
	jmp count_loop

end:
	mov rax, rcx
	ret
