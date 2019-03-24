		AREA Program, CODE, READONLY
		ENTRY
Main	mov r1,#0x38
		mov r2,#0x80
		cmp r1,r2
		bhi jump
		mov r1,r2
jump	mov r1,r3

		end