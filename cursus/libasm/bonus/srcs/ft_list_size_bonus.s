		section	.text
		global	_ft_list_size

; rdi = t_list *begin_list
_ft_list_size:
		push	rbp
		mov		rbp, rsp
		xor		rax, rax

loop:
		cmp		rdi, 0			; if (begin_list == NULL)
		je		.return			;   jmp .return
		mov		rdi, [rdi+0x08]	; begin_list = begin_list->next
		call	_ft_list_size	; ret = ft_list_size(begin_list)
		add		eax, 0x01		; ret += 1

.return:
		leave
		ret	
