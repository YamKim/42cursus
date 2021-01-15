		section	.text
		global	_is_base


_is_base:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		[rbp-0x08], rdi		; [rbp-0x08] = base
.is_base_loop:
		mov		rbx, [rbp-0x08]		; rbx = *base
		cmp		byte[rbx], 0x00
		je		.yes_base
		cmp		byte[rbx], 0x2d
		je		.no_base
		cmp		byte[rbx], 0x2b
		je		.no_base
		
		mov		rdi, [rbx]
		call	_is_space
		cmp		eax, 0x01
		je		.no_base

.is_base_loop_inc:
		add		rbx, 0x01
		mov		[rbp-0x08], rbx
		jmp		.is_base_loop
.yes_base:
		mov		eax, 0x01
		jmp		.is_base_return
		ret
.no_base:
		mov		eax, 0x00
		jmp		.is_base_return
		ret
.is_base_return:
		leave
		ret

_is_space:
		push	rbp
		mov		rbp, rsp

		mov		edx, edi
		cmp		dl, 0x20
		je		.yes_space
		cmp		dl, 0x09
		jl		.no_space
		cmp		dl, 0x0c
		jg		.no_space
		jmp		.yes_space
		
.no_space:
		mov		eax, 0x00
		jmp		.is_space_return
.yes_space:
		mov		eax, 0x01
		jmp		.is_space_return
.is_space_return:
		leave
		ret
