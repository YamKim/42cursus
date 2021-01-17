	section .text
	global	_ft_strlen

_ft_strlen:
	mov		rax, 0

if_str_null:
	cmp		byte [rdi + rax], 0
	jne		inc_idx
	ret

inc_idx:
	inc		rax
	jmp		if_str_null
