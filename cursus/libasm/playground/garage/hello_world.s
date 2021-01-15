		global	_main			;must be declared for linker (ld)
	
		section	.text
_main:							;tells linker entry point
		mov		rax, 0x2000004	;system call number (sys_write)
		mov		rdi, fd			;file descriptor (stdout)
		mov		rsi, msg
		mov		rdx, len		;message length
		syscall
	
		mov		rax, 0x2000001	;system call number (sys_write)
		xor		rdi, rdi		;file descriptor (stdout)
		syscall

		section	.data
fd		equ		1
msg		db		'Hello, world!', 0xa  ;string to be printed
len		equ		$ - msg     ;length of the string
