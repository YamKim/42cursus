		section	.text
		global	_test

_test:
		mov		rax, rdi
		mov		rbx, rsi
		push	rax
		push	rbx
		pop		rax
		pop		rbx
		ret
