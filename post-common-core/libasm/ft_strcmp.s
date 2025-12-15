.intel_syntax noprefix

.section .text
.globl ft_strcmp

ft_strcmp:
	jmp compare_loop

compare_loop:
	mov al, [rdi]
	mov bl, [rsi]

	cmp al, 0
	je end

	cmp al, bl
	jne end

	inc rsi
	inc rdi
	jmp compare_loop

end:
	movzx rax, al
	movzx rbx, bl
	sub rax, rbx
	ret

