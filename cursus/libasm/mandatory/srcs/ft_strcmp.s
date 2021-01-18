		section	.text
		global	_ft_strcmp

; rdi = char *str1
; rsi = char *str2
_ft_strcmp:
		push	rbp
		mov		rbp, rsp
		xor		rax, rax
		xor		rbx, rbx
		xor		rcx, rcx

.loop:								; while(1)
		mov		al, byte[rdi+rcx]	;   al = str[rcx]
		mov		bl, byte[rsi+rcx]	;   bl = str[rcx]
		cmp		rax, rbx			;   if (al != rbx)
		jne		.return				;     jmp .return 

		inc		ecx					;   ++ecx
		cmp		al, 0x00			;   if (al == 0)
		je		.return				;     jmp .return
		cmp		bl, 0x00			;   if (bl == 0)
		je		.return             ;     jmp .return
		jmp		.loop

.return:
		sub		rax, rbx
		leave
		ret
