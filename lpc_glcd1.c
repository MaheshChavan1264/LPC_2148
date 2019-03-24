#include"lpc214x.h"
#include"image.h"
#define ldata 0x00FF0000
#define en 1<<31
#define rs 1<<27
#define CS1 1<<26
#define CS2 1<<25  
#define rw 1<<24
#define rst 1<<30

//#define LCD_SHIFT 16


void Glcdcmd(unsigned char);
void Glcddata(unsigned int);
void MSDelay(unsigned int);
//void Glcd_disp(unsigned char);

void Glcd_disp(unsigned int *temp1)			 //display routine
{
int i,j;
for(i=0;i<8;i++) //page
 {
 	IO1SET = CS1;								//select controller 1
 	IO1CLR = CS2;  
 	Glcdcmd(0xB8 | i);      // Increment page address 
	Glcdcmd(0x40);
	for(j=0;j<64;j++)						   //display controller 1 data
	Glcddata(temp1[(i*128)+j]);
//Glcddata([*temp1++]+j);
	IO1CLR = CS1;							   //select controller 2
 	IO1SET = CS2; 
 	Glcdcmd(0xB8 | i);    // Increment page address
	Glcdcmd(0x40);
	for(j=64;j<128;j++)						   //display controller 2 data
	Glcddata(temp1[(i*128)+j]);
//Glcddata([*temp1++]+j);
 }
}

	
int main()
{
PINSEL2=0x00000000;
IODIR1= 0x8fff0000 ;
IOSET1=CS1;
IOSET1=CS2;
	
    Glcdcmd(0x3F);	  //Display ON
    MSDelay (10);                         	
	Glcdcmd(0x40);    // Set Y address as 0 (range 0-63)
	MSDelay (10); 
	Glcdcmd(0xB8);    //Set X address as 0 (page address)	(range 0-7)
	MSDelay (2000); 
	Glcdcmd(0xC0);    // Set Z address (start line=0)
	MSDelay (2000);    
	Glcd_disp(temp);
	MSDelay (2000); 
}

	
	void Glcdcmd(unsigned char value)
	{
		IOCLR1=ldata;
		IOSET1=value<<16; //LCD_SHIFT;
		IOCLR1=rs;
	  IOCLR1=rw;
		IOSET1=en;
		MSDelay(10);
		IOCLR1=en;
	}
	void Glcddata(unsigned int data)
	{
		
		IOCLR1=ldata;
		IOSET1=data<<16; //LCD_SHIFT;
		IOSET1=rs;
		IOCLR1=rw;
		IOSET1=en;
		MSDelay(10);
	  IOCLR1=en;
		
	}
	void MSDelay(unsigned int itime)
	{
		unsigned int i,j;
		for(i=0;i<itime;i++)
		for(j=0;j<5000;j++);

	}	


