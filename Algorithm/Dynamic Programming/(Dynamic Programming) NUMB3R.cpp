#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
int n, d, p, q;
//d
using namespace std;
const int MOD = 10000000;
double cache[51][101];
int connected[51][51], deg[51];
double search(int here, int days)
{
	if (days == 0)
		return (here == p ? 1.0 : 0.0);
	double &ret = cache[here][days];
	if (ret > -0.5)
		return ret;
	ret = 0.0;
	for (int there = 0; there < n; ++there)
		if (connected[here][there])
			ret += search(there, days - 1) / deg[there];
	return ret;
}

int main(void)
{
	int testcase, t;
	scanf("%d", &testcase);
	while (testcase--)
	{
		scanf("%d %d %d", &n, &d, &p);
		for (int i = 0; i < n; i++)
		{
			deg[i] = 0;
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &connected[i][j]);
				if (connected[i][j] == 1)
					deg[i]++;
			}
		}

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= d; j++)
			{
				cache[i][j] = -1.0;
			}
		}

		scanf("%d", &t);
		for (int i = 0; i < t; i++)
		{
			scanf("%d", &q);

			if (i == 0)
				printf("%.8lf", search(q, d));
			else
				printf(" %.8lf", search(q, d));
		}
		printf("\n");
	}
	return 0;
}