#include <bits/stdc++.h>
using namespace std;

int bino(int n, int r)
{
	int dp[100][100] = {
		0,
	};

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= min(r, i); j++)
			if (i == j || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

	return dp[n][k];
}

int main(void)
{
	int test_case;
	cin >> test_case;

	int N, R;
	for (int i = 0; i < test_case; i++)
	{
		cin >> N >> R;
		cout << bino(N, R) << endl;
	}
}