section .text
	global ft_strlen
	extern set_errno

ft_strlen:
	xor rax, rax

find_len:
	cmp byte [rdi], 0 ; byte -> comparing with a char
	je return_len
	inc rdi
	inc rax
	jmp find_len

return_len:
	ret
