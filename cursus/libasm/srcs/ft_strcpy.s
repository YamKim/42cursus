		section	.text
		global	_ft_strcpy

_ft_strcpy:
		xor		rcx, rcx

copy_char:
		mov		dl, byte [rsi + rcx]
		mov		byte [rdi + rcx], dl
		cmp		dl, 0
		je		done
		jne		inc_idx

inc_idx:
		inc		rcx
		jmp		copy_char

done:
		mov		rax, rdi
		ret
