		section	.text
		global	_ft_atoi

_ft_atoi:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		qword[rbp-0x08], rdi
		mov		dword[rbp-0x10], 0x00	; ret = [rbp-0x10] = 0
		mov		dword[rbp-0x18], 0x00	; sign = [rbp-0x18] = 0

		mov		rbx, qword[rbp-0x08]
		cmp		byte[rbx], 0x2d			; if ([rbx] == '-')
		je		.set_sign				;	jmp set_sign
.loop:
		mov		rbx, [rbp-0x08]			; rbx = nbr
		cmp		byte[rbx], 0x00			; if(*nbr == 0)
		je		.set_return				;	jmp set_return

		imul	eax, dword[rbp-0x10], 0x0a ; ret = ret * 10

		movsx	edx, byte[rbx]			; tmp = *nbr
		sub		edx, 0x30				; tmp = tmp - '0'

		add		eax, edx				; ret = ret + tmp
		mov		[rbp-0x10], rax			; [rbp-0x10] = ret

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
		cmp		dword[rbp-0x18], 0x01
		je		.return_neg
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
