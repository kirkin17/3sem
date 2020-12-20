#include <iostream>
#include <conio.h>

using namespace std;


void syst()
{
	string numberx;
	int number10 = 0;
	int base;
	cout << "Enter base: ";
	cin >> base;
	cout << "Enter number: ";
	cin >> numberx;
	for (int j = 0,i = numberx.length(); i >= 0; j++,--i)
	{
		number10 += numberx[i] * (pow(base, j));
	}
	cout << number10;
}


void unsigned_intff()
{
	unsigned int U_Int;
	bool num;
	cout << "Введите число" << endl;
	cin >> U_Int;
	for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; --i)
	{
		num = (U_Int & (1 << i));
		cout << num;
	}
}

void signed_intff()
{
	int Int;
	bool num;
	cout << "Введите число" << endl;
	cin >> Int;
	for (int i = sizeof(int) * 8 - 1; i >= 0; --i)
	{
		num = (Int & (1 << i));
		cout << num;
	}
}

void signed_short_intff()
{
	short Short;
	bool num;
	cout << "Введите число" << endl;
	cin >> Short;
	for (int i = sizeof(short) * 8 - 1; i >= 0; --i)
	{
		num = (Short & (1 << i));
		cout << num;
	}
}

void unsigned_short_intff()
{
	unsigned short U_Short;
	bool num;
	cout << "Введите число" << endl;
	cin >> U_Short;
	for (int i = sizeof(unsigned short) * 8 - 1; i >= 0; --i)
	{
		num = (U_Short & (1 << i));
		cout << num;
	}
}

void signed_long_intff()
{
	long Long;
	bool num;
	cout << "Введите число" << endl;
	cin >> Long;
	for (int i = sizeof(long) * 8 - 1; i >= 0; --i)
	{
		num = (Long & (1 << i));
		cout << num;
	}
}

void unsigned_long_intff()
{
	unsigned long U_Long;
	bool num;
	cout << "Введите число" << endl;
	cin >> U_Long;
	for (int i = sizeof(unsigned long) * 8 - 1; i >= 0; --i)
	{
		num = (U_Long & (1 << i));
		cout << num;
	}
}


void signed_longlong_intff()
{
	long long Long_Long;
	bool num;
	cout << "Введите число" << endl;
	cin >> Long_Long;
	for (int i = sizeof(long long) * 8 - 1; i >= 0; --i)
	{
		num = (Long_Long & (1 << i));
		cout << num;
	}
}

void unsigned_longlong_intff()
{
	unsigned long long U_Long_Long;
	bool num;
	cout << "Введите число" << endl;
	cin >> U_Long_Long;
	for (int i = sizeof(unsigned long long) * 8 - 1; i >= 0; --i)
	{
		num = (U_Long_Long & (1 << i));
		cout << num;
	}
}


void unsigned_charff()
{
	char Unsigned_Char;
	bool num;
	cout << "Введите символ" << endl;
	cin >> Unsigned_Char;
	for (int i = sizeof(char) * 8 - 1; i >= 0; --i)
	{
		num = (Unsigned_Char & (1 << i));
		cout << num;
	}
}

void signed_charff()
{
	signed char signed_char;
	bool num;
	cout << "Введите символ" << endl;
	cin >> signed_char;
	for (int i = sizeof(signed char) * 8 - 1; i >= 0; --i)
	{
		num = (signed_char & (1 << i));
		cout << num;
	}
}

void signed_floatff()
{
	float signed_float;
	bool num = 1;
	cout << "Введите число в диапазоне от 3.4E-38 до 3.4E+38\n";
	cin >> signed_float;
	for (int i = sizeof(float) * 8 - 1; i >= 0; --i)
	{
		//num = (signed_float & (1 << i));
		cout << num;
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	unsigned short int menu = -1;
	syst();
	while (1)
	{
		cout << "Output in binary\n\nMenu:\n1. int\n2. char\n3. float\n0. Exit";
		do menu = _getch(); 
		while (!((menu > '0') && (menu < '4') && (menu == '0')));
		
		if (menu == 1)
		{
			cout << "\n\n1. signed\n2. unsigned";
			do menu = _getch();
			while (!((menu > '0') && (menu < '3')));
			if (menu == '0') break;
			if (menu == '1')
			{
				cout << "\n\n1. int\n2. short\n3. long\n4. longlong";
				do menu = _getch();
				while (!((menu > '0') && (menu < '5')));
				if (menu == 1) signed_intff();
				if (menu == 2) signed_short_intff();
				if (menu == 3) signed_long_intff();
				if (menu == 4) signed_longlong_intff();
			}
			if (menu == '2')
			{
				cout << "\n\n1. int\n2. short\n3. long\n4. longlong";
				do menu = _getch();
				while (!((menu > '0') && (menu < '5')));
				if (menu == 1) unsigned_intff();
				if (menu == 2) unsigned_short_intff();
				if (menu == 3) unsigned_long_intff();
				if (menu == 4) unsigned_longlong_intff();
			}
		}
		if (menu == 2)
		{
			cout << "\n\n1. signed\n2. unsigned";
			do menu = _getch();
			while (!((menu > '0') && (menu < '3')));
			if (menu == 1) signed_charff();
			if (menu == 2) unsigned_charff();
		}
		if (menu == 3)
		{
			signed_floatff();
		}
	}
}