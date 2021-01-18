		section .text
		global	_ft_strlen

; rdi = char *str
_ft_strlen:	
		push	rbp
		mov		rbp, rsp
		xor		rax, rax			; ret = 0

.loop:								; while (1)
		cmp		byte[rdi+rax], 0x00	;   if (str[ret] != 0)
		je		.return				;     jmp .return
		inc		eax					;   ++ret
		jmp		.loop
.return:
		leave
		ret
