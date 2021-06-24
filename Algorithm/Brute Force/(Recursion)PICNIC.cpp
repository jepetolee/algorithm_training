/*
  ID : PICNIC
  USING METHOD : Brute Force
*/
#include <stdc++.h>

using namespace std;

int students;
bool areFriends[10][10];

int countPairings(bool taken[10])
{
	int priority = -1;
	for (int i = 0; i < students; i++)
	{
		if (!taken[i])
		{
			priority = i;
			break;
		}
	}

	if (priority == -1)
		return 1;
	int ret = 0;

	for (int pairWith = priority + 1; pairWith < students; ++pairWith)
	{
		if (!taken[pairWith] && areFriends[priority][pairWith])
		{
			taken[priority] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[priority] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main()
{
	bool taken[10];
	int testcase;
	cin >> testcase;
	int pairs;
	for (int i = 0; i < testcase; i++)
	{
		cin >> students >> pairs;
		memset(areFriends, false, sizeof(areFriends));
		memset(taken, false, sizeof(taken));
		for (int j = 0; j < pairs; j++)
		{
			int pair1, pair2;
			cin >> pair1 >> pair2;
			areFriends[pair1][pair2] = areFriends[pair2][pair1] = true;
		}
		cout << countPairings(taken) << endl;
	}
	return 0;
}