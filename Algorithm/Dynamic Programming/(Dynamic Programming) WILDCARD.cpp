#include <iostream>
using namespace std;

string pattern, fil;
int cache[102][102];

int matchMemoized(int w, int s)
{
	// 메모이제이션
	int& ret = cache[w][s];

	if (ret != -1) return ret;

	if (s < fil.size() && w < pattern.size() && (pattern[w] == '?' || pattern[w] == fil[s])) return ret = matchMemoized(w + 1, s + 1);

	if (w == pattern.size()) return ret = (s == fil.size());

	if (pattern[w] == '*'){
		if (matchMemoized(w + 1, s) || (s < fil.size() && matchMemoized(w, s + 1))) return ret = 1;
	}

	return ret = 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test_case;
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		
		cin >> pattern;
		int files;
		cin >> files;
		for (int c = 0; c < files; c++) {
			fill(&cache[0][0], &cache[101][101], -1);
			cin >> fil;
		   cout<<matchMemoized(0, 0);
		}

	}
}
