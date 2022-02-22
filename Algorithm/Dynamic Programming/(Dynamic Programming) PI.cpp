#include <iostream>
using namespace std;

string PI;
int cache[10002];
const int INF = 999999999;
int check(int a, int b)
{
	string M = PI.substr(a, b - a + 1);
	if (M == string(M.size(), M[0]))
		return 1;

	bool progressive = true;
	for (int i = 0; i < M.size() - 1; ++i)
		if (M[i + 1] - M[i] != M[1] - M[0])
			progressive = false;

	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;

	bool alternating = true;
	for (int i = 0; i < M.size(); ++i)
		if (M[i] != M[i % 2])
			alternating = false;
	if (alternating)
		return 4;
	if (progressive)
		return 5;
	return 10;
}

int pi(int index)
{
	if (index == PI.size())
		return 0;
	int &ret = cache[index];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int length = 3; length <= 5; length++)
		if (index + length <= PI.size())
			ret = min(ret, pi(index + length) + check(index, index + length - 1));
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test_case;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		fill(&cache[0], &cache[10001], -1);
		cin >> PI;
		cout << pi(0) << "\n";
	}
}