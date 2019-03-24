#include <LPC214X.H>

#include "font.h"

unsigned char c;
unsigned char z=0;

void ctrloff()
{

IOSET1=0x00000000; //rs=rw=en=cs1=cs2=0;
}

//DELAY FUNCTION
void delay(unsigned int j)
{ int k; for(k=0;k<=j;k++) { long i; for(i=0;i<90000;i++);
} }

void displayon()
{ ctrloff(); IOSET0=0x0000003F; IOSET1=0x001C0000; delay(5); IOSET0=0x0000003F; IOSET1=0x000C0000;
}

void displayoff()
{ ctrloff(); IOSET0=0x0000003E; IOSET1=0x001C0000; delay(5); IOSET0=0x0000003E; IOSET1=0x000C0000;
}

void setcolumn(unsigned char y)
{ if(y<64) { ctrloff(); c=y; IOSET0=0x00000040 |(y&63); //0x40 represents Column 0 IOSET1=0x00140000; delay(5); IOSET0=0x00000040 |(y&63); IOSET1=0x00040000; } else { ctrloff(); c=y; IOSET0=0x00000040|((y-64)&63); //0x40 represents Column 0 IOSET1=0x00180000; delay(5); IOSET0=0x00000040|((y-64)&63); IOSET1=0X00080000; }
}

void setpage(unsigned char x)
{ ctrloff(); IOSET0=0x000000B8|x; //0xb8 represents Page 0 IOSET0=0x001C0000; delay(5); IOSET0=0x000000B8|x; //0xb8 represents Page 0 IOSET1=0x000C0000;
}

//Function to Scroll Strings
void setstartline(unsigned char z)
{ ctrloff(); IOSET0=0x000000C0|z; //0xc0 represents Line 0 IOSET1=0x001C0000; delay(5); IOSET0=0x000000C0|z; //0xc0 represents Line 0 IOSET1=0x000C0000;
}

void lcddata(unsigned char *value,unsigned int limit)
{ unsigned int i; for(i=0;i<limit;i++) { if(c<64) { IOSET0=value[i]; IOSET1=0x00150000; delay(5); IOSET0=value[i]; IOSET1=0x00050000; c++; } else { setcolumn(c); IOSET0=value[i]; IOSET1=0x00160000; delay(5); IOSET0=value[i]; IOSET1=0x00060000; c++; } if(c>127) return; }
}

void lcdputs(unsigned char y,unsigned char x,unsigned char *str)
{ unsigned char i; unsigned int a; setcolumn(y); setpage(x); for(i=0;str[i]!=0;i++) { a=(*(str+i)-32); a*=5; lcddata(&font5x7[a],5); }
}

void clrlcd()
{ unsigned char i,j; for (i=0;i < 8;i++) { setpage(i); setcolumn(0); for (j= 0 ;j < 128; j++) lcddata(&z,1); }
}

unsigned char ar0[]="*************** ";
unsigned char ar1[]="MINOR PROJECT";
unsigned char ar2[]="ELECTRONICS AND COMMUNICATION ";
unsigned char ar3[]="************** ";

int main()
{ IODIR1=0xffffffff; IOCLR1=0xffffffff; IODIR0=0xffffffff; IOCLR0=0xffffffff; { unsigned char i; clrlcd(); displayon(); setcolumn(0); setpage(0); lcdputs(0,1,ar0); lcdputs(0,2,ar1); lcdputs(0,3,ar2); lcdputs(0,4,ar3); delay(65); delay(65);

for(i=0;i<5;i++) { displayoff(); delay(65); displayon(); delay(65); delay(65); } i=0; while(1) { setstartline(i++); //Function to Scroll Strings delay(40); }
} }