section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern set_errno
	extern ft_putstr
	extern malloc

ft_strdup:
	mov rbx, rdi
	call ft_strlen
	inc rax

	mov rdi, rax
	call malloc wrt ..plt
	cmp rax, 0
	je err

	mov rsi, rbx
	mov rdi, rax
	call ft_strcpy
	ret

err:
	mov rdi, 12
	call set_errno
	xor rax, rax
	ret
