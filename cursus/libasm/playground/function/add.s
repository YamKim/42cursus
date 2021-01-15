		section	.text
		global	_add

_add:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		[rbp-0x04], edi ; [rbp-0x04] = nbr1
		mov		[rbp-0x08], esi ; [rbp-0x08] = nbr2

		mov		edi, esi		
		call	_is_positive	; if(is_positive(nbr2))
		cmp		eax, 0x01
		jne		.add_err
		mov		eax, [rbp-0x04]
		add		eax, [rbp-0x08]
		jmp		.add_ret
.add_err:
		mov		eax, 0xffffffff
.add_ret:
		leave
		ret


_is_positive:
		push	rbp
		mov		rbp, rsp

		cmp		edi, 0x00
		jge		.pos
		mov		eax, 0x00
		jmp		.is_positive_ret
.pos:
		mov		eax, 0x01
.is_positive_ret:
		leave
		ret
