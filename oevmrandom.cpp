#include <iostream>
#include <conio.h>

void init(unsigned short int x)
{
	outp(0x43, 0xb6);
	outp(0x42, x);
	outp(0x42, (x >> 8);
	outp(0x61, inp(0x61) | 1);
}

 unsigned short int random(void)
{
	outp(0x43, 0x86);
	return(inp(0x42)+(inp(0x42)<<8));
}

void main(void)
{
	unsigned short int i,x,j;
	clrscr();
	cout << "\n\t***Generator sluchainih chisel***\n";
	cout << "\n\n Vvedite verhnuu granicu chisel->";
	cin >> x;
	init(x);
	cout << "\n Press any key...\t exit-ESC\n";
	while(getch()!= 27)
	{
j = random();
	 	for(i=0; i < j; i++) cout << ‘*’;
		cout << j << endl;
	}

}
