#include<lpc214x.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

#define ldata 0x00FF0000
#define en 1<<31
#define rs 1<<27
#define CS1 1<<26
#define CS2 1<<25  
#define rw 1<<24
#define rst 1<<30

//#define LCD_SHIFT 16


void lcdcmd(unsigned char);
void lcddata(unsigned int);
void delay(unsigned int);
void lcd_string(char* msg);

	
int main()
{
PINSEL2=0x00000000;
IODIR1= 0x8fff0000 ;
IOSET1=CS1;
IOCLR1=CS2;
	
	lcdcmd(0x3F);	  //Display ON
  delay (10);                         	
	lcdcmd(0x40);    // Set Y address as 0 (range 0-63)
	delay (10); 
	lcdcmd(0xB8);    //Set X address as 0 (page address)	(range 0-7)
	delay (2000); 
	lcdcmd(0xC0);    // Set Z address (start line=0)
	delay (2000);    
	lcd_string("MAHESH");
	delay(100);
}


void lcd_string(char* msg)
{
	uint8_t i=0;
	while(msg[i]!=0)
	{
		lcddata(msg[i]);
		i++;
	}
}


	
	void lcdcmd(unsigned char value)
	{
		IOCLR1=ldata;
		IOSET1=value<<16; //LCD_SHIFT;
		IOCLR1=rs;
	  IOCLR1=rw;
		IOSET1=en;
		delay(10);
		IOCLR1=en;
	}
	
	void lcddata(unsigned int data)
	{
		
		IOCLR1=ldata;
		IOSET1=data<<16; //LCD_SHIFT;
		IOSET1=rs;
		IOCLR1=rw;
		IOSET1=en;
		delay(10);
	  IOCLR1=en;
		
	}
	void delay(unsigned int x)
	{
		unsigned int i,j;
		for(i=0;i<x;i++)
		for(j=0;j<1275;j++);

	}	
