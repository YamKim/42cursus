		section	.text
		extern	_printf
		global	_main
_main:
		push	rbp
		mov		rbp, rsp

		mov		rdi, msg
		call	_printf

		mov		rsp, rbp
		pop		rbp
		ret	

		section	.data
msg:	db		"Hello World!",10,0
