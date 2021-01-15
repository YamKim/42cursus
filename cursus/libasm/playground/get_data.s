		section	.text
		global	_get_data

_get_data:
		push	rbp
		mov		rbp, rsp

		mov		r9, qword rsi
		mov		r8, [r9]
		mov		[rdi], r8
		mov		[rdi + 4], r8

return:
		mov		rsp, rbp
		pop		rbp
		ret
