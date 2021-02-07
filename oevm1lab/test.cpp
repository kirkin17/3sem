#include <iostream>
#include <cmath>
#include <curses.h>
#include <string>
using namespace std;

void out(char val)
{
	unsigned char mask;
	for (mask = pow(2, 7); mask != 0; mask >>= 1)
	{
		bool a = (val & mask);
		cout << a;
	}
	cout << " ";
}

void output(char val) 
{
	out(val);
}

void output(int val) 
{
	for (short i = sizeof(val); i != 0; i--)
	{
		out(val >> (8 * (i - 1)));
	}
}

void output(short val)
{
	for (short i = sizeof(val); i != 0; i--)
	{
		out(val >> (8 * (i - 1)));
	}
}

void output(float val)
{
	int* val1;
	val1 = (int*)&val;
	output(*val1);
}

bool check_range(short base, char s)
{
	if ((s >= '0' && s < '0' + base && s <= '9') || (s >= 'a' && s < 'a' + base - 10 && s <= 'z') || (s >= 'A' && s < 'A' + base - 36 && s <= 'Z')) return 1;
	else return 0;
}

int get_digit(char s)
{
	int res;
	if (s >= 'a' && s <= 'z') res = s - 'a' + 10;
	else if (s >= 'A' && s <= 'Z') res = s - 'A' + 'z' - 'a' + 11;
	else res = s - '0';
	return res;
}

int input(int base, string param)
{
	char s;
	string res;
	do
	{
		s = _getch();
		if (check_range(base, s))
		{
			cout << char(s);
			res.push_back(s);
		}
		else if (s == 8)
		{
			if (!res.empty())
			{
				res.pop_back();
				cout << "\b" << " " << "\b";
			}

		}
		else if (s == '-' && res.empty())
		{
			cout << char(s);
			res.push_back(s);
		}
		else if ((s == '.') && (param == "float"))
		{
			cout << char(s);
			res.push_back(s);
		}
	}
	while (s != 13);
	cout << endl;
	int ans = 0;
	float ans_f = 0, temp_f = 0;
	short sign = 1;
	bool f = 0;
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] == '-') sign = -1;
		else if (res[i] == '.')
		{
			f = 1;
			break;
		}
		else
		{
			if (param == "int") ans = ans * base + get_digit(res[i]);
			else ans_f = ans_f * base + get_digit(res[i]);
		}	
	}
	while (f && res.back() != '.')
	{
		temp_f = (temp_f + get_digit(res.back())) / base;
		res.pop_back();
	}
	if (param == "int")
	{
		return sign * ans;
	}
	else
	{
		ans_f = sign * (ans_f + temp_f);
		int* ret;
		ret = (int*)&ans_f;
		return *ret;
	}
}

float input(float b, string str)
{
	float* val;
	int v = input(int(b), str);
	val = (float*)&v;
	return *val;
}

int group_swap(int val, short f_pos, short s_pos, short g_size)
{
	if (f_pos < s_pos)
	{
		short temp = s_pos;
		s_pos = f_pos;
		f_pos = temp;
	}
	short status = 0;
	int ans = 0;
	for (unsigned int x = 1, i = 0; x != 0; x <<= 1)
	{
		if ((i == s_pos) || (status == 1))
		{
			status = 1;
			ans |= (val & (x << (f_pos - s_pos))) >> (f_pos - s_pos);
			if (s_pos + g_size <= i + 1) status = 0;
		}
		else if ((i == f_pos) || (status == 2))
		{
			status = 2;
			ans |= (val & (x >> (f_pos - s_pos))) << (f_pos - s_pos);
			if (f_pos + g_size <= i + 1) status = 0;
		}
		else ans |= val & x;
		i++;
	}
	return ans;
}

float group_swap(float val, short f_pos, short s_pos, short g_size)
{
	int* val_1 = (int*)&val;
	int temp = group_swap(*val_1, f_pos, s_pos, g_size);
	float* ans = (float*)&temp;
	return *ans;
}

char group_swap(char val, short f_pos, short s_pos, short g_size)
{
	return char(group_swap(int(val), f_pos, s_pos, g_size));
}

short group_swap(short val, short f_pos, short s_pos, short g_size)
{
	return short(group_swap(int(val), f_pos, s_pos, g_size));
}

int main()
{
	int option;
	do
		{
		cout << "1. int" << endl;
		cout << "2. short" << endl;
		cout << "3. long" << endl;
		cout << "4. char" << endl;
		cout << "5. float " << endl;
		cout << "0. exit" << endl;
		cin >> option;
		if (option == 1)
		{
			int v;//int
			cout << "\nInput base (2-62) " << endl;
			cin >> v;
			cout << "\nInput integer number " << endl;
			v = input(v, "int");
			cout << v << endl;
			output(v);
			cout << "\nInput first group position, second group position and groups size: " << endl;
			short a, b, c;
			cin >> a >> b >> c;
			v = group_swap(v, a, b, c);
			output(v);
			cout << endl << v << endl;
		}
		if (option == 2)
		{
			short v;//short
			cout << "\nInput short number" << endl;
			cin >> v;
			output(v);
			cout << "\nInput first group position, second group position and groups size: " << endl;
			short a, b, c;
			cin >> a >> b >> c;
			v = group_swap(v, a, b, c);
			output(v);
			cout << endl << v << endl;
		}
		if (option == 3)
		{
			
		}
		if (option == 4)
		{
			char v;//char
			cout << "\nInput the symbol" << endl;
			cin >> v;
			output(v);
			cout << "\nInput first group position, second group position and groups size: " << endl;
			short a, b, c;
			cin >> a >> b >> c;
			v = group_swap(v, a, b, c);
			output(v);
			cout << endl << v << endl;
		}
		if (option == 5)
		{
			float v;//float
			cout << "\nInput base {2-62}" << endl;
			cin >> v;
			cout << "\nInput float number" << endl;
			v = input(v, "float");
			cout << v << endl;
			output(v);
			cout << "\nInput first group position, second group position and groups size: " << endl;
			short a, b, c;
			cin >> a >> b >> c;
			v = group_swap(v, a, b, c);
			output(v);
			cout << endl << v << endl;
		}
	}
	while (option != 0);
}