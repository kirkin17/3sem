#include <iostream>
using namespace std;

int main()
{
  	short Short;
	bool num;
	std::cout << "Введите число" << endl;
	cin >> Short;
	for (int i = sizeof(short) * 8 - 1; i >= 0; --i)
	{
		num = (Short & (1 << i));
		std::cout << num;
	}
  	
	

	while(1)
	{
		cout << endl;
		int bits;
		cout << "Номер бита: ";
		cin >> bits;
		for (int i = sizeof(short) * 8 - 1; i >= 0; --i)
		{
			if (i == bits)
			{
				Short = (Short ^ (0 << bits));
				num = (Short ^ (1 << bits));
				cout << num;
				continue;
			} 
			num = (Short & (1 << i));
			std::cout << num;
		}
		cout << endl;
	}
	

}