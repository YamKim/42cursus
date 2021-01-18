		section .text
		global	_ft_list_remove_if
		extern	_free
		extern	_printf

; rdi: begin_list, [rdi]: *begin_list
; rsi: &data_ref 
; rdx: &cmp

_ft_list_remove_if:
		push	rbp
		mov		rbp, rsp

remove_first:
		cmp		qword [rdi], 0
		je		set_prev

		mov		rbx, [rdi]
		sub		rsp, 16
		mov		[rbp -  8], rdi

;		mov		rdi, msg
;		call	_printf	

		mov		rdi, [rbx]
		call	rdx
		cmp		rax, 0
		jne		set_prev


		mov		r8, rbx
		mov		rbx, [rbx + 8]
		mov		rdi, r8
		call	_free

		mov		rdi, [rbp - 8]
		mov		[rdi], rbx
		;jmp		remove_first

set_prev:
		jmp		return	
		

return:
		mov		rsp, rbp
		;add		rsp, 16
		pop		rbp
		ret

		section	.data
msg:	db		"debug=================", 10
