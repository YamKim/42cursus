		section	.text
		global	_main
		extern	_mul
		extern	_printf

_main:
		push	rbp
		mov		rbp, rsp

		mov		edi, 0x04	; nbr1 = 4
		mov		esi, 0x02	; nbr2 = 2
		call	_mul

		mov		rdi, fmt
		mov		rsi, rax
		call	_printf

.return:
		leave
		ret

		section	.data
fmt:	db		"result: %d", 10, 0
				
