#include <iostream>
#include <string>
using namespace std;


int main()
{
    string str1 = "abcdefgh";
	string str2 = "";
	for(short i = 1; i < str1.size(); i++)
	{
		str2 += str1[i];
	}
}