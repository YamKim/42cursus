		section	.text
		global	_get_sign

_get_sign:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		rbx, [rdi]
		mov		[rbp-0x08], rbx	; [rbp-0x10]=*pre

		xor		eax, eax

.loop_cond:
		mov		rbx, [rbp-0x08]	; pos = *pre
		cmp		byte[rbx], 0x2d ; if (*pos == '+')
		je		.loop			;   loop
		cmp		byte[rbx], 0x2b ; if (*pos == '-')
		je		.loop			;	loop
		jmp		.return
.loop:
		inc		eax
		add		rbx, 0x01
		mov		[rbp-0x08], rbx
		jmp		.loop_cond

.return:
		leave
		ret
