#include<lpc214x.h>
void config_uart0();
void trns_data_uart0(char data);
void trns_string_uart0(char *data);

char rcv_data_uart0();
int main (void)
{
	config_uart0();
	while(1)
	{
		char ch1;
		ch1=rcv_data_uart0();
		trns_data_uart0(ch1);
	}
	return 0;
}
void config_uart0()
{
 
 VPBDIV =0x00;
 PINSEL0 = 0x00000005; // PINSEL0 will select pin no p1.
 
 U0FCR = 0X07;       // RESET FIFO AND ENABLE IT
 U0LCR = 0x80; 
 //U0DLL = 15000000 /(16 * BaudRate);  //pclk=15MHZ
	
	U0DLL = 0x61;
	U0DLM = 0x00;
	U0LCR = 0x03;
	U0TER = 0x80;
}
void trns_data_uart0(char data)
{
	while(!(U0LSR & 0x20));
	U0THR = data;
}

void trns_string_uart0(char *data2)
{
	while(*data2)
    {
		trns_data_uart0(*data2++);
    }
}

char rcv_data_uart0()
{
	char ch;
	while(!(U0LSR & 0x01));
	ch=U0RBR;
	return(ch);
}
