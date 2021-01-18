		section .text
		global	_ft_list_sort

; rdi = t_list **begin_list 
; rsi = int (*cmp)(int, int)
_ft_list_sort:
		push	rbp
		mov		rbp, rsp

		mov		rbx, [rdi]			; rbx = *begin_list
		sub		rsp, 0x40
		mov		[rbp-0x08], rdi		; [rbp-0x08] = begin_list
		mov		[rbp-0x10], rsi		; [rbp-0x10] = cmp
		mov		[rbp-0x18], rbx		; [rbp-0x18] = *lst = *begin_list
		mov		[rbp-0x20], rbx		; [rbp-0x20] = *pos = *begin_list
		mov		[rbp-0x28], rbx		; [rbp-0x28] = *min = *begin_list
		mov		[rbp-0x30], rbx		; [rbp-0x28] = *beg = *begin_list

.loop:								; while(1) {
		mov		rbx, [rbp-0x18]		;   rbx = lst
		cmp		rbx, 0x00			;   if (lst == NULL)
		je		.return				;     break;
		mov		[rbp-0x28], rbx		;   min = lst
		mov		[rbp-0x20], rbx		;   pos = lst
		jmp		.inner_loop
.loop_inc:
		mov		rbx, [rbp-0x18]		;	rbx = lst;
		mov		rbx, [rbx+0x08]		;	
		mov		[rbp-0x18], rbx		;	lst = lst->next;	
		jmp		.loop

.inner_loop:						; while(1) {
		mov		rbx, [rbp-0x20]		;   rbx = pos;
		cmp		rbx, 0x00			;   if(rbx == NULL) 
		je		.swap				;     jmp .swap
		mov		rdx, [rbp-0x28]		;   rdx = min;
		mov		rdi, [rbx]			;   rdi = rbx->data
		mov		rsi, [rdx]			;   rsi = rdx->data
		call	[rbp-0x10]			;   
		cmp		eax, 0x00			;   if (cmp(rdi, rsi) > 0)
		jl		.set_min			;     jmp .set_min
.inner_loop_inc:
		mov		rbx, [rbp-0x20]		;   rbx = pos
		mov		rbx, [rbx+0x08]		;	rbx = rbx->next
		mov		[rbp-0x20], rbx		;   pos = pos->next
		jmp		.inner_loop

.set_min:
		mov		rbx, [rbp-0x20]		; rbx = pos
		mov		[rbp-0x28], rbx 	; min = rbx
		jmp		.inner_loop_inc

.swap:
		mov		r12, [rbp-0x18]		; r12 = lst
		mov		r11, [rbp-0x28]		; r11 = min
		
		mov		rbx, [r12]			; rbx = r12->data
		mov		rdx, [r11]			; rdx = r11->data
		mov		[r12], rdx			; lst->data = rdx
		mov		[r11], rbx			; min->data = rbx
		
		mov		[rbp-0x18], r12		; [rbp-0x18] = lst
		mov		[rbp-0x28], r11		; [rbp-0x18] = min
		jmp		.loop_inc

.return:
		mov		rdi, [rbp-0x08]
		mov		rax, [rbp-0x30]
		mov		[rdi], rax
		leave
		ret
