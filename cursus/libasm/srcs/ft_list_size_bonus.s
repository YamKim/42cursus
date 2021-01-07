;		section	.text
;		global	_ft_list_size
;
;_ft_list_size:
;		push	rbp
;		mov		rbp, rsp
;		xor		rax, rax
;
;loop:
;		cmp		rdi, 0
;		je		return
;		inc		rax
;		mov		rdi, qword [rdi + 8]
;		jmp		loop
;
;return:
;		mov		rsp, rbp
;		pop		rbp
;		ret	
		
		section	.text
		global	_ft_list_size

_ft_list_size:
		;push	rbp
		;mov		rbp, rsp
		xor		rax, rax

loop:
		cmp		rdi, 0
		je		return
		mov		rdi, qword [rdi + 8]
		call	_ft_list_size
		add		rax, 1

return:
		;mov		rsp, rbp
		;pop		rbp
		ret	
