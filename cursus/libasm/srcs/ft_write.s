	%define MAC_SYSCALL(nbr) 0x2000000 | nbr
	%define WRITE 4

	section	.text
	global	_ft_write
	extern	___error

_ft_write:	
	mov		rax, MAC_SYSCALL(WRITE)
	syscall
	jc		manage_err
	ret

manage_err:
	push	rax
	call	___error
	pop		rdi
	mov		[rax], rdi
	mov		rax, -1 
	ret
