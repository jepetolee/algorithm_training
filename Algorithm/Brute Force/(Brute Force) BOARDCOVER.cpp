/*
  ID : BOARDCOVER
  USING METHOD : Brute Force
*/
#include <stdc++.h>
using namespace std;

const int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}};

bool Bset(vector<vector<int>> &board, int y, int x, int type, int delta)
{
	bool check = true;

	for (int i = 0; i < 3; i++)
	{
		int ny = y + coverType[type][i][0];
		int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			check = false;

		else if ((board[ny][nx] += delta) > 1)
			check = false;
	}
	return check;
}

int cover(vector<vector<int>> &board)
{
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)
			break;
	}

	if (y == -1)
		return 1;
	int ret = 0;

	for (int i = 0; i < 4; i++)
	{
		if (Bset(board, y, x, i, 1))
			ret += cover(board);
		Bset(board, y, x, i, -1);
	}
	return ret;
}

int main()
{
	int testcase, h, w;
	cin >> testcase;

	while (testcase--)
	{
		char temp;
		int empty = 0;
		cin >> h >> w;
		vector<vector<int>> board(h, vector<int>(w, 0));

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> temp;
				if (temp == '#')
					board[i][j] = 1;
				else
					empty++;
			}
		}

		if (empty % 3 != 0)
			cout << 0;
		else
			cout << cover(board) << endl;
	}
}