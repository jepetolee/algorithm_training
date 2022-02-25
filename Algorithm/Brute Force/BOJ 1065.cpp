#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

void arithmetic_sequence(int num)
{
	int cnt = 0;
	for (int i = 1; i <= num; i++)
	{
		if (i < 100)
			cnt++;
		else if (int(i / 100) - int((i % 100) / 10) == int(i % 100 / 10) - i % 10)
			cnt++;
	}
	cout << cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int num;
	cin >> num;
	arithmetic_sequence(num);
}