	section .text
	global	_ft_list_remove_if
	extern	_free

; rdi = t_list **begin_list
; rsi = void *data_ref
; rdx = int (*cmp)()
_ft_list_remove_if:
	push	rbp
	mov		rbp, rsp

	mov		rbx, [rdi]				; rdi = *begin_list
	sub		rsp, 0x40
	mov		qword[rbp-0x08], rdi	; [rbp-0x08] = begin_list
	mov		qword[rbp-0x10], rsi	; [rbp-0x10] = data_ref
	mov		qword[rbp-0x18], rdx	; int (*cmp)()

	mov		qword[rbp-0x20], rbx	; *curr = *begin_list
	mov		qword[rbp-0x28], 0x00	; *prev = NULL

.loop:								; while(1){
	mov		rbx, [rbp-0x20]			;   rbx = curr
	cmp		rbx, 0x00				;   if (curr == NULL)
	je		.return					;     jmp .return
	mov		rdi, [rbx]				;   rdi = curr->data
	mov		rsi, [rbp-0x10]			;   rsi = data_ref
	call	[rbp-0x18]				;   rax = cmp(curr->data, data_ref)
	cmp		rax, 0x00				;   if (rax == 0)
	je		.remove					;     jmp .remove
.loop_inc:
	mov		rbx, [rbp-0x20]			;   rbx = curr
	mov		[rbp-0x28], rbx			;   prev = rbx
	mov		rbx, [rbx+0x08]			;   rbx = curr->next
	mov		[rbp-0x20], rbx			;   curr = rbx
	jmp		.loop					; }
.return:
	leave
	ret

.remove:
	mov		rbx, [rbp-0x28]			; rbx = prev
	mov		rdx, [rbp-0x20]			; rdx = curr
	mov		rdx, [rdx+0x08]			; rdx = curr->next
	mov		[rbp-0x30], rdx			; [rbp-0x30] = rdx
	cmp		rbx, 0x0				; if (prev != NULL)
	jne		.remove_set				;   jmp .remove_set
	mov		rbx, [rbp-0x08]			; rbx = begin_list
	mov		[rbx], rdx				; *begin_list = curr->next
	jmp		.remove_free
.remove_set:
	mov		rdx, [rbp-0x30]			; rdx = curr->next
	mov		[rbx+0x08], rdx			; (*begin_list)->next
.remove_free:
	mov		rdi, [rbp-0x20]
	call	_free					; free(begin_list)
.remove_inc:
	mov		rdx, [rbp-0x30]			; rdx = curr->next;
	mov		[rbp-0x20], rdx			; curr = rdx;
	jmp		.loop
