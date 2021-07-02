// Divide & Conquer QUADTREE

#include <stdc++.h>

using namespace std;

string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = reverse(it), upperRight = reverse(it), lowerLeft = reverse(it), lowerRight = reverse(it);
    
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

void main() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		string sentence;
		cin >> sentence;

		string::iterator it = sentence.begin();
		cout << reverse(it)<<endl;
	}
}