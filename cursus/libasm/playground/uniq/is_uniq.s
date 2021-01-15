		section	.text
		global	_is_uniq

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
		jmp		.is_uniq_loop			;
		
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
