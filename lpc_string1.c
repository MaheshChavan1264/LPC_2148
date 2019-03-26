#include <lpc214X.H>
#include "font.h"
 
unsigned char c;
unsigned char z=0;
 
void ctrloff()
{    
    IOSET1=0x00000000;
}
 
//DELAY FUNCTION
void delay(unsigned int x)
{    
    unsigned int i,j;    
    for(i=0;i<x;i++);
		for(j=0;j<1275;i++);
}
 
void displayon()
{
    ctrloff();
    IOSET1=0x1C3F;
    delay(500);
    IOSET1=0x0C3F;
    delay(500);
}
 
void displayoff()
{    
    ctrloff();
    IOSET1=0x1C3E;
    delay(500);    
    IOSET1=0x0C3E;
    delay(500);
}
 
void setcolumn(unsigned char y)
{    unsigned char c;
    if(y<64)    
    {        
        ctrloff();        
        c=y;        
        IOSET1=0x1440 |(y&63);      //0x40 represents Column 0        
        delay(500);
        IOSET1=0x0440 |(y&63);    
        delay(500);
    }    
    else    
    {        
        ctrloff();        
        c=y;        
        IOSET1=0x1840|((y-64)&63);      //0x40 represents Column 0        
        delay(500);        
        IOSET1=0x0840|((y-64)&63);    
        delay(500);
    }
}
 
void setpage(unsigned char x)
{    
    ctrloff();    
    IOSET1= 0x1CB8|x;       //0xb8 represents Page 0    
    delay(500);
    IOSET1= 0x0CB8|x;       //0xb8 represents Page 0    
    delay(500);
}
 
//Function to Scroll Strings
void setstartline(unsigned char z)            
{    
    ctrloff();    
    IOSET1=0x1CC0|z;       //0xc0 represents Line 0    
    delay(500);    
    IOSET1=0x0CC0|z;       //0xc0 represents Line 0                      
    delay(500);
}
 
void lcddata(unsigned char *value,unsigned int limit)
{    
    unsigned int i;
    unsigned char v;
    for(i=0;i<limit;i++)    
    {
        unsigned char c;
				if(c<64)        
        {            
            v=value[i];    
            IOSET1=0x1500|v;
            delay(500);            
            IOSET1=0x0500|v;        
            delay(500);
            c++;        
        }        
        else        
        {            
            setcolumn(c);            
            IOSET1=0x1600|v;        
            delay(500);            
            IOSET1=0x0600|v;            
            delay(500);
            c++;        
        }
        if(c>127)          
        return;    
    }
}
 
void lcdputs(unsigned char y,unsigned char x,unsigned char *str)
{    
    unsigned char i;    
    unsigned int a;    
    setcolumn(y);    
    setpage(x);    
    for(i=0;str[i]!=0;i++)    
    {        
        a=(*(str+i)-32);        
        a*=5;        
        lcddata(&font[a],5);    
    }
}
 
void clrlcd()
{    
    unsigned char i,j;    
    for (i=0;i < 8;i++)    
    {    
        setpage(i);    
        setcolumn(0);        
        for (j= 0 ;j < 128; j++)        
        lcddata(&z,1);    
    }
}
 
unsigned char ar0[]="***************  ";
unsigned char ar1[]="MIT Academy of Engineering";
unsigned char ar2[]="E&TC department"; 
unsigned char ar3[]="**************  ";
 
int main()
{    
    unsigned char i;    
    clrlcd();    
    displayon();    
    setcolumn(0);    
    setpage(0);    
    lcdputs(0,1,ar0);    
    lcdputs(0,2,ar1);    
    lcdputs(0,3,ar2);    
    lcdputs(0,4,ar3);    
    delay(65000);    
    delay(65000);    
    for(i=0;i<5;i++)    
    {        
        displayoff();        
        delay(65000);        
        displayon();        
        delay(65000);        
        delay(65000);    
    }    
    i=0;    
    while(1)    
    {        
        setstartline(i++);     //Function to Scroll Strings        
        delay(40000);    
    }
}
