	section .text
	global	_ft_list_sort
	extern	_free

_ft_list_sort:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 0x40
	mov		qword[rbp-0x08], rdi	; t_list *begin_list
	mov		qword[rbp-0x10], rsi	; int (*cmp)(int, int)
	mov		qword[rbp-0x18], rdi	; t_list *lst
	mov		qword[rbp-0x20], rdi	; t_list *pos
	mov		qword[rbp-0x28], rdi	; t_list *min
	push	rbx
	push	r12
	push	r11

.loop:							;while(1){
	mov		rbx, [rbp-0x18]		;	rbx = lst;
	cmp		rbx, 0x0			;	if (lst == NULL)
	je		.return				;		break;
	mov		[rbp-0x28], rbx		;	min = lst;
	mov		[rbp-0x20], rbx		;	pos = lst;

.inner_loop:					;	while(1){
	mov		r12, [rbp-0x20]		;		r12 = pos;
	cmp		r12, 0x0			;		if (pos == NULL)
	je		.swap				;			call .swap;

	mov		rdi, [r12]			;		r12 = pos->data;
	mov		r11, [rbp-0x28]		;		r11 = min;	
	mov		rsi, [r11]			;		r11 = min->data;
	call	[rbp-0x10]			;		if (cmp(r12, r11) < 0)
	jl		.set_min			;			min = pos;
	call	.swap				;		call .swap
	jmp		.inner_loop_inc		;		pos = pos->next;
								;	}
								;}
.inner_loop_inc:
	mov		r12, [r12 + 8]		;
	mov		[rbp-0x20], r12		; pos = pos->next;
	jmp		.inner_loop

.set_min:
	mov		[rbp-0x28], r12		; min = pos;
	jmp		.inner_loop_inc		; pos = pos->next;

.swap:
	mov		r12, [rbp-0x18]		; r12 = lst
	mov		r11, [rbp-0x28]		; r11 = min

	mov		rbx, [r12]			; rbx = *lst
	mov		rdx, [r11]			; rdx = *min
	mov		[r12], rdx			; *lst = *min
	mov		[r11], rbx			; *min = rbx

	mov		[rbp-0x18], r12		; modified lst
	mov		[rbp-0x28], r11		; modified min

.loop_inc:
	mov		rbx, [rbx + 8]		;	
	mov		[rbp-0x18], rbx		;	lst = lst->next;	
	jmp		.loop

.return:
	push	r11
	pop		r12
	pop		rbx
	leave
	ret
