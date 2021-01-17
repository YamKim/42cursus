		section	.text
		global	_ft_strcpy

; rdi = char *str1
; rsi = char *str2
_ft_strcpy:
		push	rbp
		mov		rbp, rsp
		xor		rcx, rcx

.loop:
		mov		dl, byte [rsi + rcx]
		mov		byte [rdi + rcx], dl
		cmp		dl, 0
		je		.return

.loop_inc:
		inc		rcx
		jmp		.loop

.return:
		mov		rax, rdi
		leave
		ret
