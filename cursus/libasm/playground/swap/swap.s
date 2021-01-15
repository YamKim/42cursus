		section	.text
		global	_swap

_swap:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		qword[rbp-0x08], rdi ; [rbp-0x08] = a;
		mov		qword[rbp-0x10], rsi ; [rbp-0x16] = b;

		mov		r12, [rbp-0x08]		 ; r12 = a;
		mov		r11, [rbp-0x10]		 ; r11 = b;

		mov		ebx, [r12]			 ; rbx = *a; 
		mov		edx, [r11]			 ; 
		mov		[r12], edx			 ; *a = *b;
		mov		[r11], ebx			 ; *b = rbx;

		mov		rdi, r12
		mov		rsi, r11
		leave
		ret
