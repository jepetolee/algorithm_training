// Divide & Conquer power of number

#include <stdc++.h>

using namespace std;
// 핵심은 시간 복잡도가 O(n) 에서 O(lgn)으로 변했다는 점이다.


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