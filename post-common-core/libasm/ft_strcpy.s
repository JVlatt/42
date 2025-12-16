.intel_syntax noprefix

.section .rodata
debug_fmt:
    .string "len = %ld\n"

.section .text
.globl ft_strcpy
.extern printf

ft_strcpy:
	mov rax, rdi
	jmp copy_loop

copy_loop:
	mov al, [rsi]
	mov [rdi], al

	cmp al, 0
	je end

	inc rsi
	inc rdi

	jmp copy_loop

end:
	ret

