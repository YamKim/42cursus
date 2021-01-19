		section	.text
		global	_mul

; rdi = nbr1
; rsi = nbr2
_mul:
		push	rbp
		mov		rbp, rsp

		mov		eax, edi	; eax = nbr1
		mul		esi			; eax = eax * nbr2

.return:
		leave
		ret
