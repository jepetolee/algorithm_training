#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define string endl "\n";
using namespace std;
char list[1023][2045];
void drawT(int row, int colum, int size);

void drawRT(int row, int colum, int size) {

	if (size == 1) {
		list[row][colum] = '*';
		return;
	}
	for (int i = 0; i < 2 * size - 1; i++)
		list[row ][colum + i] = '*';
	
	for (int i = 1; i < size-1; i++) {
		list[row + i][colum + i] = '*';
		list[row + i][colum + 2*size-2-i] = '*';
	}

	
	list[row+size-1][colum +size-1] = '*';

	drawT(row +1, colum + (size + 1) / 2, (size - 1) / 2);
	return;
}

void drawT(int row, int colum, int size) {
	if (size == 1) {
		list[row][colum] = '*';
		return;
	}
	list[row][colum+size-1] = '*';
	for (int i = 1; i < size-1; i++) {
		list[row + i][colum+size-1-i] = '*';
		list[row + i][colum+size - 1+i] = '*';
	}
	
	for (int i = 0; i < 2 * size-1; i++) 
		list[size + row-1][colum+i] = '*';
	
	
	
	drawRT(row+(size-1)  / 2, colum + (size + 1) / 2, (size - 1) / 2);
	return;
}

void star(int num){
	int size = (1<<num) - 1;
	cout << size<<endl;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < 2 * size - 1; j++)
			list[i][j] = ' ';

	if (num%2 ==1)
	drawT(0,0,size);
	else
	drawRT(0, 0, size);
    
	for (int i = 0; i < size; i++) {
		for(int j=0;j<2*size-1;j++)
			cout << list[i][j];
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	fill(&list[0][0], &list[1022][2044], '\0');
	int number;
	cin >> number;
		
	star(number);
}