section .text
	global is_null
	extern set_errno

is_null:
	xor rax, rax
	ret