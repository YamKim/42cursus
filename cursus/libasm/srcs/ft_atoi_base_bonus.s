		section	.text
		global	_ft_atoi_base

_ft_atoi_base:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		[rbp-0x08], rdi			; [rbp-0x08] = nbr
		mov		[rbp-0x10], rsi			; [rbp-0x10] = base

		mov		rdi, [rbp-0x10]			; rdi = base
		call	_is_base				;
		cmp		eax, 0x00				; if (is_base == 0)	
		je		.return					;	return (0);

		mov		eax, 0x01
.return:
		leave
		ret
		
_is_base:								; rdi = base
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		[rbp-0x08], rdi			; [rbp-0x08] = base

		mov		rbx, [rbp-0x08]			; rbx = base
		cmp		byte[rbx], 0x00			; if (base[0] == 0)
		je		.no_base				;	return (0);
		cmp		byte[rbx+0x01], 0x00	; if (base[1] == 0)
		je		.no_base				;	return (0);

		mov		rdi, [rbp-0x08]
		call	_is_uniq				; if (is_uniq(base) != 1)
		cmp		eax, 0x01				;	return (0);
		jne		.no_base
.is_base_loop:
		mov		rbx, [rbp-0x08]			; rbx = *base
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
		mov		eax, 0x01				; return (1);
		jmp		.is_base_return
.no_base:
		mov		eax, 0x00				; return (0);
		jmp		.is_base_return
.is_base_return:
		leave
		ret

_is_uniq:								; rdi = base
		push	rbp
		mov		rbp, rsp
		sub		rsp, 0x40
		mov		[rbp-0x08], rdi
		mov		[rbp-0x10], rdi
.is_uniq_loop:							;while (1)
		mov		rbx, [rbp-0x08]			;	rbx = str(=[rbp-0x08])
		cmp		byte[rbx], 0x00			;	if (*str == 0)
		je		.yes_uniq				;		return (1)
		add		rbx, 0x01				;	
		mov		[rbp-0x10], rbx			;	[rbp-0x10] = rbx + 1
		mov		[rbp-0x18], rbx			;	[rbp-0x18] = for using as tmp
		jmp		.is_uniq_inner_loop
.is_uniq_loop_inc:
		mov		rbx, [rbp-0x10]			;
		mov		[rbp-0x08], rbx			;	[rbp-0x08] = [rbp-0x10]
		jmp		.is_uniq_loop
.is_uniq_inner_loop:					;	while (1)	
		mov		rbx, [rbp-0x08]			;		rbx = [rbp-0x08]
		mov		rdx, [rbp-0x18]			;		rdx = [rbp-0x18]
		cmp		byte[rdx], 0x00			;		if (*rdx == 0)
		je		.is_uniq_loop_inc		;			break;
		mov		cl, byte[rdx]
		cmp		byte[rbx], cl			;		if (*rbx == *rdx)
		je		.no_uniq				;			return (0);
		add		rdx, 0x01				;		rdx = rdx + 1
		mov		[rbp-0x18], rdx			;		[rbp-0x10] = tmp + 1
		jmp		.is_uniq_inner_loop
.yes_uniq:
		mov		eax, 0x01
		jmp		.is_uniq_return
.no_uniq:
		mov		eax, 0x00
		jmp		.is_uniq_return
.is_uniq_return:
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
