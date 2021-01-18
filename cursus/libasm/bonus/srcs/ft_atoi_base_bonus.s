		section	.text
		global	_ft_atoi_base
		extern	_ft_strlen

_ft_atoi_base:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 0x40
		mov		dword[rbp-0x08], 0x00	; ret = [rbp-0x08] = 0 
		mov		qword[rbp-0x10], rdi	; [rbp-0x10] = nbr
		mov		qword[rbp-0x18], rsi	; [rbp-0x18] = base
		mov		dword[rbp-0x20], 0x00	; sign = [rbp-0x20] = 0

		mov		rdi, [rbp-0x18]			; rdi = base
		call	_is_base
		cmp		eax, 0x00				; if (is_base == 0)	
		je		.return					;   return (0);

.skip_space:							; while (1)
		mov		rbx, [rbp-0x10]			;   rbx = nbr
		mov		rdi, [rbx]
		call	_is_space				
		cmp		al, 0x00				;   if (_is_space(*nbr))    
		je		.get_sign				;     jmp .get_sign
		add		rbx, 0x01
		mov		[rbp-0x10], rbx			;   rbx = rbx + 1
		jmp		.skip_space

.get_base_type:
		mov		rdi, [rbp-0x18]			
		call	_ft_strlen				; base_type = ft_strlen(base)
		mov		qword[rbp-0x28], rax	; [rbp-0x28] = base_type

.loop:
		mov		rbx, qword[rbp-0x10]	; rbx = nbr
		cmp		byte[rbx], 0x00			; if (*nbr == 0)
		je		.set_return				;   jmp .set_return

		push	rbx

		mov		rdi, [rbp-0x18]
		mov		rsi, [rbx]
		call	_get_add_nbr			; get_add_nbr(base, *nbr)
		cmp		eax, dword[rbp-0x28]
		jge		.set_return
		mov		dword[rbp-0x30], eax	; [rbp-0x30] = add

		mov		eax, dword[rbp-0x08]	; eax = ret
		mul		dword[rbp-0x28]			; ret = ret * base_type

		add		eax, dword[rbp-0x30]	; ret = ret + add
		mov		[rbp-0x08], rax			; [rbp-0x08] = ret

.loop_inc:
		pop		rbx
		add		rbx, 0x01
		mov		[rbp-0x10], rbx
		jmp		.loop

.set_return:
		mov		ebx, 0x02
		mov		eax, dword[rbp-0x20]
		cdq
		div		ebx
		cmp		edx, 0x01				; if (sign % 2 == 1)
		je		.return_neg				;	jmp .return_neg	
.return_pos:
		mov		eax, dword[rbp-0x08]
		mov     dword[rbp-0x04], eax
		jmp		.return
.return_neg:
		xor		eax, eax
		sub		eax, dword[rbp-0x08]	; eax = 0 - eax
		mov		dword[rbp-0x04], eax
.return:
		leave
		ret

.get_sign:
		xor		eax, eax				; sign = 0
.get_sign_loop_cond:
		mov		rbx, [rbp-0x10]			; rbx = nbr
		cmp		byte[rbx], 0x2d			; if (*nbr == '-')
		je		.get_sign_loop			;   loop
		cmp		byte[rbx], 0x2b			; if (*nbr == '+')
		je		.get_sign_loop			;   loop
		jmp		.get_base_type
.get_sign_loop:
		cmp		byte[rbx], 0x2d			; if (*nbr == '-')
		je		.get_sign_inc_neg
.get_sign_loop_inc
		mov		[rbp-0x20], rax
		add		rbx, 0x01				;
		mov		[rbp-0x10], rbx			; [rbp-0x10 = rbx + 1
		jmp		.get_sign_loop_cond
.get_sign_inc_neg:
		inc		eax
		jmp		.get_sign_loop_inc
		
_is_base:								; rdi = base
		push	rbp
		mov		rbp, rsp
		sub		rsp, 0x40
		mov		qword[rbp-0x10], rdi	; [rbp-0x10] = base

		mov		rbx, [rbp-0x10]			; rbx = base
		cmp		byte[rbx], 0x00			; if (base[0] == 0)
		je		_return_no				;   return (0);
		cmp		byte[rbx+0x01], 0x00	; if (base[1] == 0)
		je		_return_no				;   return (0);

		mov		rdi, [rbp-0x10]
		call	_is_uniq				; if (is_uniq(base) != 1)
		cmp		eax, 0x01				;   return (0);
		jne		_return_no
.loop:
		mov		rbx, [rbp-0x10]			; rbx = *base
		cmp		byte[rbx], 0x00			; if (*base == 0x00)
		je		_return_yes				;   return (1);
		cmp		byte[rbx], 0x2d			; if (*base == '-')
		je		_return_no				;   return (0);
		cmp		byte[rbx], 0x2b			; if (*base == '+')
		je		_return_no				;   return (0);
		
		mov		rdi, [rbx]				; rdi = *base
		call	_is_space
		cmp		eax, 0x01				; if (is_space(*base))
		je		_return_no				;   return (0);
.loop_inc:
		add		rbx, 0x01
		mov		[rbp-0x10], rbx			; [rbp-0x10] = base + 1
		jmp		.loop

_is_uniq:								; rdi = base
		push	rbp
		mov		rbp, rsp
		sub		rsp, 0x40
		mov		[rbp-0x10], rdi
		mov		[rbp-0x18], rdi
.loop:									; while (1)
		mov		rbx, [rbp-0x10]			;   rbx = str(=[rbp-0x10])
		cmp		byte[rbx], 0x00			; 	if (*str == 0)
		je		_return_yes				; 	  return (1)
		add		rbx, 0x01				; 	
		mov		[rbp-0x18], rbx			; 	[rbp-0x18] = rbx + 1
		mov		[rbp-0x20], rbx			; 	[rbp-0x20] = for using as tmp
		jmp		.inner_loop
.loop_inc:
		mov		rbx, [rbp-0x18]			; 
		mov		[rbp-0x10], rbx			; 	[rbp-0x10] = [rbp-0x18]
		jmp		.loop
.inner_loop:							; 	while (1)	
		mov		rbx, [rbp-0x10]			; 	  rbx = [rbp-0x10]
		mov		rdx, [rbp-0x20]			; 	  rdx = [rbp-0x20]
		cmp		byte[rdx], 0x00			; 	  if (*rdx == 0)
		je		.loop_inc				; 	  	break;
		mov		cl, byte[rdx]
		cmp		byte[rbx], cl			; 	  if (*rbx == *rdx)
		je		_return_no				; 	  	return (0);
		add		rdx, 0x01				; 	  rdx = rdx + 1
		mov		[rbp-0x20], rdx			; 	  [rbp-0x18] = tmp + 1
		jmp		.inner_loop

_is_space:
		push	rbp
		mov		rbp, rsp
		mov		edx, edi				; edx = c
		cmp		dl, 0x20				; if (c == ' ')
		je		_return_yes				; 	return (1);
		cmp		dl, 0x09
		je		_return_yes
		cmp		dl, 0x0a
		je		_return_yes
		cmp		dl, 0x0b
		je		_return_yes
		cmp		dl, 0x0c
		je		_return_yes
		cmp		dl, 0x0d
		je		_return_yes
_return_no:
	   	mov		eax, 0x00
	   	jmp		_return_is
_return_yes:
	  	mov		eax, 0x01
	  	jmp		_return_is
_return_is:
		leave
		ret	

_get_add_nbr:
		push	rbp
		mov		rbp, rsp
		xor		eax, eax
		mov		rbx, rdi
		mov		rdx, rsi
.loop:
		cmp		byte[rbx], 0x00	; if (*base == 0)
		je		.return			;	break;
		cmp		byte[rbx], dl
		je		.return
		
		inc		eax
		add		rbx, 1
		jmp		.loop
.return:
		leave
		ret
