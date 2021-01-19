		section	.text
		global	_make_pointer
		extern	_malloc

; rdi = int **nbr
_make_pointer:
		push	rbp
		mov		rbp, rsp

		sub		rsp, 0x40
		mov		qword[rbp-0x08], rdi  ; [rbp-0x08] = nbr
		mov		edi, 0x08
		call	_malloc				  ; rax = malloc(0x08)
		mov		dword[rax], 0x04	  ; rax[0] = 0x02
		mov		dword[rax+0x04], 0x02 ; rax[0] = 0x02
		mov		rdi, [rbp-0x08]		  ; rdi = nbr
		mov		[rdi], rax		      ; *nbr = rax

.return:
		leave
		ret
