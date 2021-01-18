		%define	STRUCTURE_SIZE 16

		section	.text
		extern	_malloc
		global	_ft_list_push_front

; rdi = t_list **begin_list
; rsi = void *data

_ft_list_push_front:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		qword[rbp-0x08], rdi
		mov		qword[rbp-0x10], rsi
		cmp		qword[rbp-0x08], 0		; if (begin_list == 0)
		je		.return					;   jmp .return

		mov		rdi, STRUCTURE_SIZE
		call	_malloc					; ret = malloc(16)
		cmp		rax, 0					; if (ret == 0)
		je		.return					;   jmp .return

		mov		rbx, [rbp-0x10]			; rbx = data
		mov		qword[rax], rbx			; ret->data = data
		mov		rdx, [rbp-0x08]	
		mov		rdx, qword[rdx]			; rdx = (*begin_list)->next
		mov		qword[rax+0x08], rdx	; ret->next = rdx
		mov		rdi, [rbp-0x08]			; rdi = begin_list
		mov		qword[rdi], rax			; *begin_list = ret
.return:
		leave
		ret	
