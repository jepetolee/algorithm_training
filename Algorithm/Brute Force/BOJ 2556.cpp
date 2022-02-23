#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define string endl "\n";
using namespace std;

void star(int num)
{
	for (int k = 0; k < num; k++)
	{
		for (int i = 0; i < num; i++)
			cout << "*";
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