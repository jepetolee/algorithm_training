#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#define string endl "\n";
using namespace std;

void star(int num)
{
	for (int i = 0; i < num; i++)
	{
		if (i % 2 == 0)
		{
			cout << " ";
		}

		for (int i = 1; i < num; i++)
			cout << "* ";

		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#define string endl "\n";
		using namespace std;

	void star(int num)
	{
		for (int i = 1; i <= num; ++i)
		{
			if (i % 2 == 0)
			{
				cout << " ";
			}

			for (int i = 0; i < num; i++)
				cout << "* ";

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
	cin.tie(nullptr);
	int number;
	cin >> number;

	star(number);
}