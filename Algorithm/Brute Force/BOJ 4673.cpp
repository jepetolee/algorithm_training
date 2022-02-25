#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

void self_number()
{
	int arr[10000] = {
		1,
	};
	for (int i = 0; i < 10000; i++)
	{
		if (i < 10)
			arr[i + i] = 1;
		else if (i < 100)
			arr[i + i / 10 + i % 10] = 1;
		else if (i < 1000)
			arr[i + i / 100 + i % 100 / 10 + i % 10] = 1;
		else if (i < 10000)
		{
			int temp = i + i / 1000 + i % 1000 / 100 + i % 100 / 10 + i % 10;
			if (temp < 10000)
				arr[temp] = 1;
		}
	}
	for (int i = 0; i < 10000; i++)
		if (!arr[i])
			cout << i << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	self_number();
}