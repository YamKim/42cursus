		%define	STRUCTURE_SIZE 16
		section	.text
		extern	_malloc
		extern	_printf
		global	_ft_list_remove_if

_ft_list_remove_if:
		;push	rbp
		;mov		rbp, rsp

		xor		rax, rax

		cmp		rdi, 0
		je		return
		cmp		qword [rdi], 0
		je		return

;	rdi: t_list **begin_list
;	rsi: void	*data_ref
;	rdx: int	*cmp()
;	rcx: void	*free_fct(void *)

is_ref_data:
		push	rcx					; save free_fct
		mov		rcx, qword [rdi]	; rcx = t_list *begin_list
		push	qword [rcx + 8]	; r8 = t_list *(begin_list)->next
		push	rdi					; save **begin_list
		mov		rdi, qword [rcx]	; rdi = begin_list->data	
		call	rdx
		cmp		rax, 0
		jne		case1
		jmp		case2

case1:
		pop		rdi
		pop		r8
		pop		rcx					; restore free_fct
		;mov		rsp, rbp
		;pop		rbp
		call	_ft_list_remove_if
		
		mov		rax, 1
		jmp		return
		
case2:
		pop		rdi					; restore **begin_list
		pop		rcx					; restore free_fct

		mov		rax, 2
		jmp		return

return:
		;mov		rsp, rbp
		;pop		rbp
		ret

		section	.data
msg:	db		"HERE===============",0
