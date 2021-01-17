		section	.text
		global	_ft_atoi_base
		extern	_ft_strlen

_ft_atoi_base:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		qword[rbp-0x08], rdi
		mov		dword[rbp-0x10], 0x00	; ret = [rbp-0x10] = 0
		mov		dword[rbp-0x18], 0x00	; sign = [rbp-0x18] = 0
		mov		qword[rbp-0x20], rsi	; [rbp-0x20] = base

		; ft_strlen
		mov		rdi, [rbp-0x20]
		call	_ft_strlen
		mov		[rbp-0x28], rax			; [rbp-0x28]=base_type

		mov		rbx, qword[rbp-0x08]
		cmp		byte[rbx], 0x2d			; if ([rbx] == '-')
		je		.set_sign				;	jmp set_sign
.loop:
		mov		rbx, [rbp-0x08]			; rbx = nbr
		cmp		byte[rbx], 0x00			; if(*nbr == 0)
		je		.set_return				;	jmp set_return
		push	rbx

		; get_add_nbr
		mov		rdi, [rbp-0x20]
		mov		rsi, [rbx]
		call	_get_add_nbr			; get_add_nbr(base, *nbr)
		mov		dword[rbp-0x30], eax	; [rbp-0x30] = add

		mov		eax, dword[rbp-0x10]	; eax = ret
		mul		dword[rbp-0x28]			; ret = ret * base_type

		add		eax, dword[rbp-0x30]	; ret = ret + add
		mov		[rbp-0x10], rax			; [rbp-0x10] = ret

		pop		rbx
		add		rbx, 0x01				; rbx = rbx + 1
		mov		[rbp-0x08], rbx			; [rbp-0x08] = str + 1
		jmp		.loop

.set_sign:
		mov		edx, dword[rbp-0x18]
		inc		edx
		mov		dword[rbp-0x18], edx

		mov		rbx, [rbp-0x08]
		add		rbx, 0x01
		mov		[rbp-0x08], rbx
		jmp		.loop

.set_return:
		mov		ebx, 0x02
		mov		eax, dword[rbp-0x18]
		cdq
		div		ebx
		cmp		edx, 0x01				; if (sign % 2 == 1)
		je		.return_neg				;	jmp .return_neg	
.return_pos:
		mov		eax, dword[rbp-0x10]
		mov     dword[rbp-0x0d], eax
		jmp		.return
.return_neg:
		xor		eax, eax
		sub		eax, dword[rbp-0x10]
		mov		dword[rbp-0x0d], eax
.return:
		mov		eax, dword[rbp-0x0d]
		leave
		ret

_get_add_nbr:
		push	rbp
		mov		rbp, rsp
		xor		eax, eax
		mov		rbx, rdi
		mov		rdx, rsi
.loop:
		cmp		byte[rbx], 0x00	; if (*base == 0)
		je		.return			;	break;
		cmp		byte[rbx], dl
		je		.return
		
		inc		eax
		add		rbx, 1
		jmp		.loop
.return:
		leave
		ret
