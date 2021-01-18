		%define	STRUCTURE_SIZE 16
		section	.text
		global	_ft_list_cmp_if

;	rdi: t_list **begin_list
;	rsi: void	*data_ref
;	rdx: int	*cmp()

_ft_list_cmp_if:
		push	rbp
		mov		rbp, rsp

		mov		rax, 1

		cmp		rdi, 0
		je		return
		cmp		qword [rdi], 0
		je		return

		mov		rbx, [rdi]
		mov		r8, qword [rbx]
		mov		r9, qword [rbx + 8]

		sub		rsp, 16
		mov		qword [rbp - 8], r8		; [rbp - 8] = begin_list->data
		mov		qword [rbp - 16], r9	; [rbp - 16] = begin_list->next

		mov		rdi, qword [rbp - 8]	; rdi = begin_list->data
										; rsi = data
		call	rdx
		cmp		rax, 0
		jne		case1
		je		case2
		
case1:
		add		rbx, 8
		mov		rdi, rbx
		call	_ft_list_cmp_if			; consider about not finding case
		jmp		return
		
case2:
		mov		rax, 0
		jmp		return

return:
		mov		rsp, rbp
		pop		rbp
		ret
