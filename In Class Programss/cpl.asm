org 0000h
	mov tmod,#10h
	again:mov tl1,#26h
	mov th1,#71h
	setb tr1
	back:jnb tf1,back
	clr tr1
	cpl p1.5
	clr tf1
	sjmp again
	end
		
