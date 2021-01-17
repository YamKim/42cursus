		%define MAC_SYSCALL(nbr) 0x2000000 | nbr
		%define WRITE 4
		
		section	.text
		global	_ft_write
		extern	___error

; rdi = int fd
; rsi = const void *buf
; rdx = size_t nbyte
_ft_write:	
		mov		rax, MAC_SYSCALL(WRITE) ; rax = 0x2000004
		syscall							; ft_write(fd, buf, nbyte)
		jc		.manage_err				; jc: error flag
.return:
		ret

.manage_err:
		push	rax						; save prev_rax
		call	___error
		pop		qword[rax]				; [rax] = prev_rax
		mov		rax, -1					; rax = -1
		jmp		.return
