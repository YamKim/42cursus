	section .text
	global	_ft_list_remove_if
	extern	_free

_ft_list_remove_if:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 0x40
	mov		qword[rbp-0x08], rdi	; t_list **begin_list
	mov		qword[rbp-0x10], rsi	; void *data_ref
	mov		qword[rbp-0x18], rdx	; int (*cmp)()
	mov		rdi, [rdi]				; rdi = *begin_list
	mov		qword[rbp-0x20], rdi	; t_list *curr = *begin_list
	mov		qword[rbp-0x28], 0x0	; t_list *prev = NULL
	push	rbx
	push	r12

.loop:								;while(1){
	mov		rbx, [rbp-0x20]		;	rbx = curr;
	cmp		rbx, 0x0				;	if (curr == NULL)
	je		.return					;		break;
	mov		rdi, [rbx]				;	rdi = curr->data;
	mov		rsi, [rbp-0x10]		;	rsi = data_ref;
	call	[rbp-0x18]			;	rax = cmp(curr->data, data_ref);
	cmp		rax, 0x0				;	if (rax == 0)
	je		.remove					;		.drop
.loop_inc:
	mov		rbx, [rbp-0x20]		;	rbx = curr;
	mov		[rbp-0x28], rbx		;	prev = curr;
	mov		rbx, [rbx + 8]			;	rbx = curr->next;
	mov		[rbp-0x20], rbx		;	curr = curr->next;
	jmp		.loop					;}

.remove:
	mov		rbx, [rbp-0x28]		;rbx = prev;
	mov		r12, [rbp-0x20]		;r12 = curr;
	mov		r12, [r12 + 8]			;r12 = curr->next;
	cmp		rbx, 0x0				;if (prev == NULL)
	jne		.remove_set				;{
	mov		rbx, [rbp-0x08]		;	rbx = begin_list;
	mov		[rbx], r12				;	*begin_list = curr->next;
	jmp		.remove_free			;}
.remove_set:						;else
	mov		[rbx + 8], r12			;	prev->next = curr->next;
.remove_free:
	mov		rdi, [rbp-0x20]
	call	_free
.remove_inc:
	mov		[rbp-0x20], r12		;curr = curr->next;
	jmp		.loop
.return:
	pop		r12
	pop		rbx
	leave
	ret
