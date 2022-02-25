#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#define string endl "\n";
using namespace std;
char list[405][401];

void draw_shape(int row, int colum, int size)
{
	if (size == 1)
	{
		list[row][colum] = '*';
		return;
	}
	for (int i = 0; i < size; i++)
	{
		list[row][colum + i] = '*';
		list[row + size + 1][colum + i] = '*';

		if ((size == 5) && (i == size - 2))
		{
			list[row + 2][colum + i] = '*';
			list[row + 2][colum + i - 1] = '*';
			list[row + 3][colum + i - 1] = '*';
		}
		else if (i == size - 2)
			list[row + 2][colum + i] = '*';
	}
	for (int i = 0; i < size + 2; i++)
	{

		if (i > 0)
			list[row + i][colum] = '*';

		if (i > 1)
			list[row + i][colum + size - 1] = '*';
	}
	if (size == 5)
		draw_shape(row + 4, colum + 2, size - 4);
	else
		draw_shape(row + 2, colum + 2, size - 4);
	return;
}

void star(int num)
{
	int size = 4 * num - 3;
	for (int i = 0; i < size + 2; i++)
		for (int j = 0; j < size; j++)
			if (i != 1)
				list[i][j] = ' ';
	if (num == 1)
	{
		cout << "*";
		return;
	}
	draw_shape(0, 0, size);
	for (int i = 0; i < size + 2; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == 1)
			{
				cout << list[i][0];
				break;
			}
			cout << list[i][j];
		}
		cout << endl;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int number;
	cin >> number;

	star(number);
}