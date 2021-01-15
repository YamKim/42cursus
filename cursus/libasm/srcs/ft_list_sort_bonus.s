		section .text
		global	_ft_list_sort
		extern	_printf

_ft_list_sort:
		push	rbp
		mov		rbp, rsp
		
		sub		rsp, 0x40
		mov		[rbp-0x08], rdi		; t_list *begin_list
		mov		[rbp-0x10], rsi		; int (*cmp)(int, int)
		mov		[rbp-0x18], rdi		; t_list *lst
		mov		[rbp-0x20], rdi		; t_list *pos
		mov		[rbp-0x28], rdi		; t_list *min
		push	rbx
		push	rdx

.loop:								;while(1){
		mov		rbx, [rbp-0x18]		;	rbx = lst;
		cmp		rbx, 0x00			;	if (lst == NULL)
		je		.return				;		break;
		mov		[rbp-0x28], rbx		;	min = lst;
		mov		[rbp-0x20], rbx
		jmp		.inner_loop
.loop_inc:
		mov		rbx, [rbp-0x18]		;	rbx = lst;
		mov		rbx, [rbx+0x08]		;	
		mov		[rbp-0x18], rbx		;	lst = lst->next;	
		jmp		.loop

.inner_loop:						;	while(1){
		mov		rbx, [rbp-0x20];	;		rbx = pos;
		cmp		rbx, 0x00			;		if(pos == NULL) 
		je		.swap				;			call .swap;
		mov		rdx, [rbp-0x28]		;		rdx = min;
		mov		rdi, [rbx]			;		rdi = pos->data;
		mov		rsi, [rdx]			;		rsi = min->data;
		call	[rbp-0x10]			;		if (cmp(rdi, rsi) > 0)
		cmp		eax, 0x00
		jl		.set_min			;		call .set_min;
.inner_loop_inc:
		mov		rbx, [rbp-0x20]		;		rbx = pos;
		mov		rbx, [rbx+0x08]
		mov		[rbp-0x20], rbx		;		pos = pos->next;
		jmp		.inner_loop

.set_min:
		mov		rbx, [rbp-0x20]
		mov		[rbp-0x28], rbx 	; min = pos;
		jmp		.inner_loop_inc

.swap:
		push	r12
		push	r11

		mov		r12, [rbp-0x18]		; r12 = lst
		mov		r11, [rbp-0x28]		; r11 = min
		
		mov		rbx, [r12]			; rbx = *lst
		mov		rdx, [r11]			; rdx = *min
		mov		[r12], rdx			; *lst = *min
		mov		[r11], rbx			; *min = rbx
		
		mov		[rbp-0x18], r12		; modified lst
		mov		[rbp-0x28], r11		; modified min

		pop		r11
		pop		r12
		jmp		.loop_inc

.return:
		pop		rdx
		pop		rbx
		mov		rdi, [rbp-0x08]
		mov		rax, rdi
		leave
		ret
