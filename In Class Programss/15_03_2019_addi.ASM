		AREA Program, CODE, READONLY
		ENTRY
 MAIN 	LDR R1,#value1			//load value1 in r1
		LDR R2,#value2			//load value2 in r2
		CMP R1,R2				// Compare r1 and r2 
		BHI jump				// jump if r1 larger
		LDR R1,R2				//if r2 is larger then move r2 in r1
jump 	STR R1,RESULT			// store larger no at memory location of reuslt
value1 	DCD &10001202
value2 	DCD &10001204
RESULT 	DCD 0X00000007
		END