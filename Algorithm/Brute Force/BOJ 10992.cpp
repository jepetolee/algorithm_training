#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define string endl "\n";
using namespace std;

void star(int num)
{
	if (num == 1)
		cout << "*";
	else
	{
		for (int i = 0; i < num - 1; i++)
		{
			if (i == 0)
			{
				for (int j = 1; j < num - 1; j++)
					cout << " ";
				cout << " * " << endl;
			}
			else
			{
				for (int j = 1; j < num - i; j++)
					cout << " ";
				cout << "*";
				for (int j = 0; j < 2 * i - 1; j++)
					cout << " ";
				cout << "*" << endl;
			}
		}
		for (int i = 0; i < 2 * num - 1; i++)
			cout << "*";
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