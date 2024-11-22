section .text
	global ft_read
	extern set_errno

ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jl err
	ret

err:
	neg rax
	mov rdi, rax
	call set_errno
	mov rax, -1
	ret
