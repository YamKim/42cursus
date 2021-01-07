		%define	STRUCTURE_SIZE 16

		section	.text
		extern	_malloc
		global	_ft_list_push_front

_ft_list_push_front:
		push	rbp
		mov		rbp, rsp
		cmp		rdi, 0
		je		return

		push	rdi
		push	rsi

		mov		rdi, STRUCTURE_SIZE
		call	_malloc
		cmp		rax, 0
		je		return

		pop		rsi
		mov		qword [rax], rsi
		pop		rdi
		mov		rdx, qword [rdi]
		mov		qword [rax + 8], rdx
		mov		qword [rdi], rax
		jmp		return

return:
		mov		rsp, rbp
		pop		rbp
		ret	
		
		
