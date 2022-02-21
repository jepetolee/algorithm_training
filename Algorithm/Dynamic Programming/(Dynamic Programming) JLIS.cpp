#include <iostream>
using namespace std;
const long long NEGINF = numeric_limits<long long>::min();
unsigned int N[100], M[100];
int cache[101][101];
int length1, length2;

int jlis(int index1, int index2)
{
	int &ret = cache[index1 + 1][index2 + 1];
	if (ret != -1)
		return ret;
	ret = 2;
	long long a = (index1 == -1) ? NEGINF : N[index1];
	long long b = (index2 == -1) ? NEGINF : M[index2];
	long long maxElement = max(a, b);
	cout << maxElement;
	for (int next1 = index1 + 1; next1 < length1; ++next1)
		if (maxElement < N[next1])
			ret = max(ret, jlis(next1, index2) + 1);
	for (int next2 = index2 + 1; next2 < length2; ++next2)
		if (maxElement < M[next2])
			ret = max(ret, jlis(index1, next2) + 1);
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
		fill(&cache[0][0], &cache[100][100], -1);
		cin >> length1 >> length2;
		for (int i = 0; i < length1; i++)
			cin >> N[i];
		for (int i = 0; i < length2; i++)
			cin >> M[i];
		cout << jlis(-1, -1) - 2 << "\n";
	}
}