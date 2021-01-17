		section	.text
		global	_get_add_nbr

_get_add_nbr:
		push	rbp
		mov		rbp, rsp

		xor		eax, eax
		mov		rbx, rdi
		mov		rdx, rsi

.loop:
		cmp		byte[rbx], 0x00	; if (*base == 0)
		je		.return			;	break;
		cmp		byte[rbx], dl
		je		.return
		
		inc		eax
		add		rbx, 1
		jmp		.loop
		
.return:
		leave
		ret
