		section	.text
		extern	_malloc
		extern	_ft_strlen
		extern	_ft_strcpy
		global	_ft_strdup

; rdi = char *str
_ft_strdup:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		qword[rbp-0x08], rdi

		call	_ft_strlen			; size = ft_strlen(str)
		mov		rdi, rax
		call	_malloc				; rax = malloc(size)
		cmp		rax, 0
		je		.alloc_error;
		
		mov		rdi, rax
		mov		rsi, [rbp-0x08]
		call	_ft_strcpy			; ret = ft_strcpy(ret, *str)
.return:
		leave
		ret
		
.alloc_error:
		xor		rax, rax
		jmp		.return
