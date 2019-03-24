#include<LPC214x.h>
void I2C_Init();
void I2C_Start();
void delay();
void
	
void I2CInit()
{
	PINSEL0 &=0x00000050;
	I2C0CONCLR=0xff;
	
	I2C0SCLH=0x4B
	I2C0SCLL=0x4B
	
	I2C0CONSET=0x80
}

void I2C_Start()
{
	unsigned status;
	I2C0CONCLR=0xFF;
	I2C0CONSET=0x90;
	while(
}

int main()
{
	Uart_Start();
	printf("Writing data:\n")
	
	
	
	