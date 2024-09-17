section .text
	global ft_strcpy
	extern set_errno
	extern is_null

ft_strcpy:
	test rsi, rsi ; Test if pointer is NULL
	jz return_dest ; Jump to is_null if src is null
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
