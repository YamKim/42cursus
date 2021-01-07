		section	.text
		extern	_malloc
		extern	_ft_strlen
		extern	_ft_strcpy
		global	_ft_strdup

_ft_strdup:
		call	_ft_strlen
		push	rdi
		mov		rdi, rax
		call	_malloc
		cmp		rax, 0
		je		fail_allocation;
		pop		rdi
		mov		rsi, rdi
		mov		rdi, rax
		call	_ft_strcpy
		ret
		
fail_allocation:
		xor		rax, rax
		ret
