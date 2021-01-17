		section	.text
		global	_get_nbr
		extern _ft_strlen

_get_nbr:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		[rbp-0x08], rdi			; [rbp-0x08]=nbr
		mov		[rbp-0x10], rsi			; [rbp-0x16]=base

		mov		rdi, [rbp-0x10]
		call	_ft_strlen		
		mov		[rbp-0x18], rax			; [rbp-0x18]=ft_strlen(base)
		mov		dword[rbp-0x20], 0x00	; [rbp-0x20]=0
.loop:
		mov		rbx, [rbp-0x08]
		cmp		byte[rbx], 0x00
		je		.return
		mov		rdi, [rbp-0x10]
		mov		rsi, [rbx]
		call	_get_add_nbr
		add		eax, dword[rbp-0x20]
		mov		[rbp-0x20], rax
		;jmp		.return;;;;;;;;;;;;;;

		add		rbx, 0x01
		mov		[rbp-0x08], rbx
		jmp		.loop
.return:
		mov		rax, [rbp-0x20]
		leave
		ret


_get_add_nbr:
		push	rbp
		mov		rbp, rsp

		xor		eax, eax
		mov		rbx, rdi		; rbx = base
		mov		rdx, rsi		; rdx = c
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
