#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#define string endl "\n";
using namespace std;
void cycle(int num)
{
	if (num == 1)
	{
		cout << "*";
		return;
	}
	if (num % 2 == 1)
	{
		cout << "*";
		for (int j = 0; j < (num - 1) / 2; j++)
			cout << " *";
		cout << endl;
		for (int j = 0; j < (num - 1) / 2; j++)
			cout << " *";
		cout << endl;
	}
	else
	{
		cout << "*";
		for (int j = 0; j < num / 2 - 1; j++)
			cout << " *";
		cout << endl;
		for (int j = 0; j < num / 2; j++)
			cout << " *";
		cout << endl;
	}
	return;
}

void star(int num)
{
	for (int i = 0; i < num; i++)
	{
		cycle(num);
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