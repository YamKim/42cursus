			global	_main

			section	.text
_main:
			mov		rdx, buf
			mov		r8,	1
			mov		r9, 0	
line:
			mov		byte [rdx], charStar
			inc		rdx
			inc		r9
			cmp		r9, r8
			jne		line
lineDone:
			mov		byte [rdx], charNline
			inc		rdx
			inc		r8
			mov		r9, 0
			cmp		r8, maxLines
			jng		line
done:
			mov		rax, 0x02000004
			mov		rdi, fd
			mov		rsi, output
			mov		rdx, dataSize
			syscall
			mov		rax, 0x02000001
			xor		rdi, rdi
			syscall

			section .data
buf:		db		dataSize

			section .bss
charStar	equ		0x2a
charNline	equ		0x0a
fd			equ		1
maxLines	equ		8
dataSize	equ		44
