#include <bits/stdc++.h>
using namespace std;

int N, board[100][100], cache[100][100];

int jump(int y, int x)
{
	if (y >= N || x >= N)
		return 0;
	if (y == N - 1 && x == N - 1)
		return 1;
	int &ret = cache[y][x];
	if (ret != -1)
		return ret;
	int jumpsize = board[y][x];
	return ret = (jump(y + jumpsize, x) || jump(y, x + jumpsize));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		memset(cache, -1, sizeof(cache));

		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> board[i][j];

		cout << (jump(0, 0) ? "YES\n" : "NO\n");
	}
}