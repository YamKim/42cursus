		section	.text
		global	_ft_strcmp

_ft_strcmp:
		xor		rax, rax
		xor		rbx, rbx
		xor		rcx, rcx

if_same_char:
		mov		al, byte [rdi + rcx]
		mov		bl, byte [rsi + rcx]
		cmp		rax, rbx
		je		inc_idx
		jne		done

inc_idx:
		inc		rcx
		cmp		al, 0
		je		done
		cmp		bl, 0
		je		done
		jmp		if_same_char

done:
		sub		rax, rbx
		ret
