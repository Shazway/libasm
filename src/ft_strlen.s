section .text
	global ft_strlen
	extern set_errno
	extern is_null

ft_strlen:
	test rdi, rdi ; Test if pointer is NULL
	jz is_null ; Jump to is_null if (char *s) first parameter is null
	xor rax, rax

find_len:
	cmp byte [rdi], 0 ; byte -> comparing with a char
	je return_len
	inc rdi
	inc rax
	jmp find_len

return_len:
	ret
