#include <iostream>
using namespace std;
int h,triangle[100][100];
int cache[100][100];

int path(int y, int x) {
	if (y == h - 1) return triangle[y][x];
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	return ret = (path(y + 1, x + 1)< path(y + 1, x)? path(y+1,x):path(y+1,x+1)) + triangle[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test_case;
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		fill(&cache[0][0], &cache[99][99], -1);
		cin>> h;
			for (int y = 0; y < h; y++)
				for(int x=0;x<=y;x++)
					cin >> triangle[y][x];
		cout << path(0, 0) << "\n";
	}
}