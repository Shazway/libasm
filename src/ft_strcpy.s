section .text
	global ft_strcpy
	extern set_errno

ft_strcpy:
	mov rax, rdi

cpy_src:
	cmp byte [rsi], 0
	je return_dest
	movsb
	jmp cpy_src

return_dest:
	mov byte [rdi], 0
	mov rdi, rax
	ret
