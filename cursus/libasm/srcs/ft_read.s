	%define MAC_SYSCALL(nbr) 0x2000000 | nbr
	%define READ 3

	section	.text
	global	_ft_read
	extern	___error

_ft_read:	
	mov		rax, MAC_SYSCALL(READ)
	syscall
	jc		manage_err
	ret

manage_err:
	push	rax
	call	___error
	pop		qword [rax]
	mov		rax, -1
	ret
