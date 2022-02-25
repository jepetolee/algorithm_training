#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#define string endl "\n";
using namespace std;
char list[401][401];

void draw_shape(int row, int colum, int size) {
	if (size == 1) {
		list[row][colum] = '*';
		return;
	}
	for (int i = 0; i < size; i++) {
		list[row][colum + i] = '*';
		list[row + size - 1][colum + i] = '*';
		if (i > 0) {
			list[row + i][colum] = '*';
			list[row + i][colum + size - 1] = '*';
		}
	}
	draw_shape(row + 2, colum + 2, size - 4);
	return;
}

void star(int num) {
	int size = 4 * num - 3;
	for (int i = 0; i < size; i++) 
		for (int j = 0; j < size; j++)
			 list[i][j]=' ';
		

	draw_shape(0, 0, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << list[i][j];
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