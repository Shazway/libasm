section .text
	global set_errno
	extern __errno_location

set_errno:
	call __errno_location wrt ..plt
	mov [rax], rdi
	ret
