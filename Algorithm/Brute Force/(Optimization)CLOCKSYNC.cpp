/*
  ID : CLOCKSYNC
  USING METHOD : Brute Force
*/

/* 학습한 테크닉: 벡터 자료형을 사용할때 auto를 사용해
   벡터의 포인터를 당기면 배열처럼 활용이 가능하다.
*/
#include <stdc++.h>

using namespace std;

const vector<vector<int>> linked = {
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}};

void cpush(vector<int> &clocks, int switchnumbers)
{

	for (auto t : linked[switchnumbers])
		clocks[t] = (clocks[t] == 12) ? 3 : (clocks[t] + 3);
}

bool areAligned(const vector<int> &clocks)
{

	for (auto c : clocks)
		if (c != 12)
			return false;

	return true;
}

int solve(vector<int> &clocks, int cnt)
{

	if (cnt == 10)
		return areAligned(clocks) ? 0 : 99999;

	int ret = 99999;

	for (int j = 0; j < 4; ++j)
	{
		ret = min(ret, j + solve(clocks, cnt + 1));
		cpush(clocks, cnt);
	}

	return ret;
}

int main()
{

	int testcase;
	auto times = vector<int>(16);
	cin >> testcase;

	while (testcase--)
	{

		int temp;

		for (int i = 0; i < 16; i++)
		{
			cin >> temp;
			times[i] = temp;
		}

		int ret = solve(times, 0);

		ret = (ret == 9999) ? -1 : ret;
		cout << ret << endl;
	}
}