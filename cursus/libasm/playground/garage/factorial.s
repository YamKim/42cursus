		global _factorial
	
		section .text

_factorial:
        mov		rax, rdi
        cmp		rax, 1
        jne		L1
        mov		rax, 1
        jmp		L2

L1:
		mov		rdx, rax
		push	rdx
		dec		rax	
		mov		rdi, rax
		call	_factorial
		pop		rdx
		mul		qword rdx

L2:
		ret
