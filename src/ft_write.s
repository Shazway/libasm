section .text
	global ft_write
	extern set_errno

ft_write:
	mov rax, 1
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
