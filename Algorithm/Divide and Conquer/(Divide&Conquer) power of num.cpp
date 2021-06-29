// Divide & Conquer power of number

#include <stdc++.h>

using namespace std;
// �ٽ��� �ð� ���⵵�� O(n) ���� O(lgn)���� ���ߴٴ� ���̴�.


int power_of_num(int num, int exp ) {
	if (exp == 0) return 1;
	if(exp%2 ==1) return  num * power_of_num(num,exp-1);
	return power_of_num(num, exp/2)* power_of_num(num, exp / 2);
}

int main() {
	int N,e;
	cin >> N>>e;
	cout << power_of_num(N,e)<<endl;
}