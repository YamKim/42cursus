		section	.text
		global	_swap_list

_swap_list:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		qword[rbp-0x08], rdi ; [rbp-0x08] = lst1;
		mov		qword[rbp-0x10], rsi ; [rbp-0x16] = lst2;

		mov		r12, [rbp-0x08]		 ; r12 = *lst1;
		mov		r11, [rbp-0x10]		 ; r11 = *lst2;

		mov		rbx, [r12]			 ; rbx = *a; 
		mov		rdx, [r11]			 ; 
		mov		[r12], rdx			 ; *a = *b;
		mov		[r11], rbx			 ; *b = rbx;

		mov		rdi, r12
		mov		rsi, r11
		leave
		ret
