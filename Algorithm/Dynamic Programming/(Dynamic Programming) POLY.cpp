#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 10000000;
int cache[101][101];

int poly(int number, int index) {
	if (index == number) return 1;
	int& result = cache[number][index];
	if (result != -1)return result;
	result = 0;
	for (int next = 1; next <= number - index; ++next) {
        if(index ==0)result += poly(number - index, next)% MOD;
		else result += ((next + index - 1)* poly(number - index, next))% MOD;
		result %= MOD;
	}
	return result;
}

int main() {
   ios_base::sync_with_stdio(false);
   int testcase;
   cin >> testcase;
   while (testcase--) {
	   fill(&cache[0][0], &cache[100][100], -1);
	   int number;
	   cin >> number;
	   cout<< poly(number, 0)<<endl;

   }
}