#include <iostream>
#include <vector>
using namespace std;

vector<int> enter(int size, int base)
{
	vector<int> number(size);
	int i = 0;
	while (1)
	{
		char c = getchar();
		if ((c >= '0') && (c <= '9'))
		{
			if (i != size)
			{
				number.push_back(c);
				i++;
				for (int j = number.size(); j >= 0; --j)
				{
					cout << number[j];
				}
			}
		}
		else if (c == '\b')
		{
			if (!(number.empty()))
			{
				number.pop_back();
				--i;
				for (int j = number.size(); j >= 0; --j)
				{
					cout << number[j];
				}
			}
		}
		else if (c == '\n') return number;
	}
}

void signed_intff()
{
	
}

int main()
{
	char c = 49;
	cout << c;
	cout << char('1');
	
}