		AREA Program, CODE, READONLY
		ENTRY
Main	ldr r1,value1
		ldr r2,value2
		mul r3,r1,r2
		str r3,result
value1	dcd &10101111
value2	dcd &22021021
result 	dcd 0x00000008
		end