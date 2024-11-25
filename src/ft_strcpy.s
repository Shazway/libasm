section .text
	global ft_strcpy

ft_strcpy:
	mov rdx, rdi

.copy_loop:
	mov al, [rsi]
	mov [rdi], al
	inc rsi
	inc rdi
	test al, al
	jnz .copy_loop
	mov rax, rdx
	ret
