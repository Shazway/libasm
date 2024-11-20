section .text
	global ft_strcmp
	extern ft_strlen
	extern set_errno

ft_strcmp:
	xor rax, rax

cmp_len:
	push rdi
	push rsi
	call ft_strlen
	mov rbx, rax
	pop rdi
	pop rsi

	push rsi
	push rdi
	mov rdi, rsi
	call ft_strlen
	mov rcx, rax
	pop rsi
	pop rdi

	cmp rbx, rcx
	jg s1_greater
	jl s2_greater

cmp_bytes:
	cmp byte [rdi], 0
	je equal
	cmp byte rdi, rsi
	jg s1_greater
	jl s2_greater
	inc rdi
	inc rsi
	jmp cmp_bytes

s1_greater:
	mov rax, 1
	ret

s2_greater:
	mov rax, -1
	ret
equal:
	mov rax, 0
	ret
