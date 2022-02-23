#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define string endl "\n";
using namespace std;

char list[3072][6143];//3*2^10, 2*(3*2^10)-1

void draw(int length, int col) {
	list[length][col] = '*';
	list[length + 1][col - 1] = '*';
	list[length + 1][col + 1] = '*';
	for (int i = 0; i < 5; i++)
		list[length + 2][col - 2 + i]='*';
}

void draw_star(int length, int row, int col){
	if (length == 3){
		draw(row, col);
		return;  
	}

	draw_star(length / 2, row, col);
	draw_star(length / 2, row + length / 2, col - length / 2);  
	draw_star(length / 2, row + length / 2, col + length / 2);  
}

void star(int num) {
	draw_star(num,0,num-1);
	
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 2 * num - 1; j++) {
			cout << list[i][j];
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int number;
	cin >> number;
	for (int i = 0; i < number; i++)
		for (int j = 0; j < 2 * number - 1; j++)
			list[i][j] = ' ';
	
	star(number);
}