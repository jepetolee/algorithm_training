// Divide & Conquer sum

#include <stdc++.h>

using namespace std;
// �ٽ��� �ð� ���⵵�� O(n) ���� O(lgn)���� ���ߴٴ� ���̴�.
int quick_sum(int num) {
	if (num == 1) return 1;
	if(num%2 ==1) return num+quick_sum(num - 1);
	return 2 * quick_sum(num / 2) + (num / 2)* (num / 2);
}

int main() {
	int N;
	cin >> N;
	cout << quick_sum(N)<<endl;
}