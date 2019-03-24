		AREA Program, CODE, READONLY
		ENTRY
Main	ldr r1,value1
		ldr r2,value2
		cmp r1,r2
		bhi jump
		mov r1,r2
jump	str r1,result
value1	dcd &11
value2	dcd &22
result 	dcd 0x00000008
		end

//For lager number
//		AREA Program, CODE, READONLY
	//	ENTRY
//Main	ldr r1,value1
	//	ldr r2,value2
		//cmp r1,r2
		//bhi jump
		//mov r1,r2
//jump	str r2,result
//value1	dcd &11
//value2	dcd &22
//result 	dcd 0x00000008
//		end