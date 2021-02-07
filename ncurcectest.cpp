#include <iostream>


long pow(int a, int n)
{
	long res = 0;
	for (int i = 0; i < n; i++)
	{
		res += res * a;
	}
	return res;
}


int main()
{
    std::cout << pow(2,3);
}