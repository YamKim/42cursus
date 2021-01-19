		section	.text
		global	_swap

; rdi = int *nbr1
; rsi = int *nbr2
_swap:
		push	rbp
		mov		rbp, rsp

		mov		ebx, dword[rdi]	 ; ebx = *nbr1 
		mov		edx, dword[rsi]	 ; edx = *nbr2
		mov		dword[rdi], edx	 ; *nbr1 = edx
		mov		dword[rsi], ebx	 ; *nbr2 = ebx

		leave
		ret
