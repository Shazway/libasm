section .text
	global set_errno
	extern _errno_location

set_errno:
	call _errno_location

	mov [rax], rdi
	ret