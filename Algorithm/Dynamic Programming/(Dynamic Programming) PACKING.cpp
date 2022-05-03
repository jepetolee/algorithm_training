#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
string name[100];
int alloc, capacity;
int volume[100], need[100];
int cache[1001][100];
vector<string> ans;

int pack(int capacity, int item)
{
	if (item == alloc)
		return 0;
	int &ret = cache[capacity][item];
	if (ret != -1)
		return ret;
	ret = pack(capacity, item + 1);
	if (capacity >= volume[item])
		ret = max(ret, pack(capacity - volume[item], item + 1) +
						   need[item]);
	return ret;
}

void reconstruct(int capacity, int item,
				 vector<string> &picked)
{

	if (item == alloc)
		return;
	if (pack(capacity, item) == pack(capacity, item + 1))
		reconstruct(capacity, item + 1, picked);
	else
	{
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		cin >> alloc >> capacity;
		ans.clear();
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < alloc; i++)
			cin >> name[i] >> volume[i] >> need[i];
		reconstruct(capacity, 1, ans);
		cout << pack(capacity, 1) << " " << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << endl;
		}
	}
}