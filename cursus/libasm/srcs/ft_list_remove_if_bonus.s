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

		cmp		rdi, 0
		je		return
		cmp		qword [rdi], 0
		je		return

		mov		rbx, [rdi]				; rbx = *begin_list
		mov		r8 , qword [rbx]		; r8 = (*begin_list)->data
		mov		r9 , qword [rbx + 8]	; r9 = (*begin_list)->next

		sub		rsp, 32
		mov		qword [rbp -  8], r8	; [rbp - 8] = r8
		mov		qword [rbp - 16], r9	; [rbp - 16] = r9
		mov		qword [rbp - 24], rdi	; [rbp - 24] = **begin_list

		mov		rdi, qword [rbp - 8]	; rdi = (*begin_list)->data
										; rsi = *data
		call	rdx
		cmp		rax, 0
		jne		recursion

		mov		rdi, qword [rbp - 24]	; rdi = **begin_list
		mov		r9 , qword [rbp - 16]
		mov		[rdi], r9				; [rdi] = (*begin_list)->next	
		mov		qword [rbp - 32], rdi	; [rbp - 32] = **new_begin_list

		mov		
		;mov		rdi, qword [rbp -  8]
		;call	_free
		;mov		rdi, rbx
		;call	_free

		mov		rdi, qword [rbp - 32]
		call	_ft_list_remove_if
		
recursion:
		add		rbx, 8
		mov		rdi, rbx
		call	_ft_list_remove_if		; consider about not finding case
		jmp		return
		
return:
		mov		rsp, rbp
		pop		rbp
		ret
