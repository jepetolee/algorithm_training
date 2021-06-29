// Recursive sum

#include <stdc++.h>

using namespace std;
int Recursive_sum(int num) {
	if (num == 1) return 1;
	return num+Recursive_sum(num - 1);
}

int main() {
	int N;
	cin >> N;
	cout << Recursive_sum(N)<<endl;
}