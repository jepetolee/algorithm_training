#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#define string endl "\n";
using namespace std;

void star(int num) {
	for (int i = 0; i < num; i++)
		cout << "*";
	for (int i = 0; i < 2*num-3; i++)
		cout << " ";
	for (int i = 0; i < num; i++)
		cout << "*";
	cout << endl;

	for (int i = 1; i <= num - 2; i++) {
		for (int j = 0; j < i; j++) 
			cout << " ";
		cout << "*";
		for (int j = 0; j < num-2; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j <= 2*(num - (i+2)); j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < num - 2; j++)
			cout << " ";
		cout << "*";
		cout << endl;
	}

	for (int i = 0; i < num - 1; i++)
		cout << " ";
	cout << "*";
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < num - 2; i++)
			cout << " ";
		cout << "*";
	}
	cout << endl;
	
	for (int i = 1; i <= num - 2; i++) {
		for (int j = 0; j < num - i-1; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < num - 2; j++)
			cout << " ";
		cout << "*";
		for (int j = 1; j < 2 * i; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < num - 2; j++)
			cout << " ";
		cout << "*";
		cout << endl;
	}
	
	for (int i = 0; i < num; i++)
		cout << "*";
	for (int i = 0; i < 2 * num - 3; i++)
		cout << " ";
	for (int i = 0; i < num; i++)
		cout << "*";

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