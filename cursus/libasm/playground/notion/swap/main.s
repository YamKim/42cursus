		section	.text
		global	_main
		extern	_swap

_main:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		dword[rbp-0x08], 0x04	; a = 0x04
		mov		dword[rbp-0x10], 0x02	; b = 0x02

		lea		rdi, [rbp-0x08]		; nbr1 = rdi = &a
		lea		rsi, [rbp-0x10]		; nbr2 = rsi = &b 
		call	_swap

.return:
		leave
		ret


