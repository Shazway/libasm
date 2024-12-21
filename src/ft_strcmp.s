section .text
global ft_strcmp

ft_strcmp:

.loop:
	mov al, byte [rdi]
	mov bl, byte [rsi]

	cmp al, bl
	jg .greater
	jl .lesser

	test al, al
	je .equal

	inc rdi
	inc rsi
	jmp .loop

.greater:
	mov rax, 1
	ret

.lesser:
	mov rax, -1
	ret

.equal:
	mov rax, 0
	ret
