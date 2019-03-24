#include<lpc214x.h>

void delay(unsigned int x);
int main()
{
	PINSEL0 = 0x00000000;
	IO0DIR = 0x0000FF00;
	
	while(1)
	{
		IO0CLR = 0x0000FF00;
		delay(100);
		//IO0SET = 0x0000FF00;
		//delay(100);
	}
}
void delay(unsigned int x)
	{
			unsigned int i,j;
			for(i=0;i<x;i++);
			for(j=0;j<1278;j++);
	}			