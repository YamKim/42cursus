		section	.text
		global	_ft_strlen

_ft_strlen:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		[rbp-0x08], rdi

		xor		eax, eax

.loop:
		mov		rbx, [rbp-0x08]
		cmp		byte[rbx], 0x00
		je		.return

.loop_inc:
		lea		rbx, [rbx + 0x01]
		mov		[rbp-0x08], rbx
		add		eax, 0x01
		jmp		.loop

.return:
		leave
		ret
