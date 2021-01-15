		%define	STRUCTURE_SIZE 16
		section	.text
		extern	_free
		global	_ft_list_remove_if

;	rdi: t_list **begin_list
;	rsi: void	*data_ref
;	rdx: int	*cmp()
;	rcx: void	*free_fct(void *)

_ft_list_remove_if:
		push	rbp
		mov		rbp, rsp

		cmp		rdi, 0					; cmp begin_list with 0
		je		return
		cmp		qword [rdi], 0			; cmp *begin_list with NULL
		je		return

		mov		rbx, [rdi]				; rbx = &begin_list

		sub		rsp, 8
		mov		qword [rbp - 8], rdi	; [rbp - 8] = begin_list

		mov		rdi, [rbx]				; rdi = &((*begin_list)->data)
										; rsi = &data_ref
		call	rdx
		cmp		rax, 0
		jne		next

		mov		rdi, [rbp - 8]
		mov		r9, [rbx + 8]
		mov		[rdi], r9
		call	_ft_list_remove_if

		;mov		rdi, rbx
		;call	_free

		jmp		return
		
next:
		add		rbx, 8
		mov		rdi, rbx
		call	_ft_list_remove_if		; consider about not finding case
		jmp		return
		
return:
		mov		rsp, rbp
		pop		rbp
		ret
