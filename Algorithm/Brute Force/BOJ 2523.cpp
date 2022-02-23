#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define string endl "\n";
using namespace std;

void star(int num)
{
	for (int t = 1; t < 2 * num; t++)
	{
		int i = t;
		if (i <= num)
		{
			while (i--)
				cout << "*";
		}
		else
		{
			i = 2 * num - i;
			while (i--)
				cout << "*";
		}
		if (t != 2 * num - 1 || t != 0)
			cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int number;
	cin >> number;

	star(number);
}