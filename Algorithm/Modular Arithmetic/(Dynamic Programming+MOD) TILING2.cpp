#include <iostream>
using namespace std;
int Cache[101];
const int Mod = 1000000007;

int Tiling(int Width) {
	if (Width <= 1) return 1;
	int& Result = Cache[Width];
	if (Result != -1)return Result;
	return Result = (Tiling(Width - 2) + Tiling(Width - 1))%Mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int TestCase;
	cin >> TestCase;
	while (TestCase--) {
		int Width;
		cin >> Width;
		fill(&Cache[0], &Cache[100], -1);
		cout << Tiling(Width) << "\n";
	}
}