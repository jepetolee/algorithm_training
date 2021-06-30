// Divide & Conquer Karatsuba multiply
/*made by karatsuba*/
 /* O(n^log3) */
#include <stdc++.h>

using namespace std;

void normalize(vector<int>& num) {
	num.push_back(0);
	int size = num.size();
	for (int i = 0; i < size -1; i++) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
}
void addTo(vector<int>& a, const vector<int>& b, int k) {
	int Size = a.size();
	if (a.size() < b.size() + k)
		a.resize(b.size() + k);

	a.push_back(0);
	int Asize = a.size();
	
	for (int i = Size; i < Asize; i++)
		a[i] = 0;

	int Bsize = b.size();
	for (int i = 0; i < Bsize; i++)
		a[i + k] += b[i];

	normalize(a);
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			c[i + j] += a[i] * b[j];
	normalize(c);
	return c;
}

void subFrom(vector<int>& a, const vector<int>& b) {
	int Bsize = b.size();
	for (int i = 0; i < Bsize; i++)
		a[i] -= b[i];
	normalize(a);
}
vector <int> karatsuba(const vector<int>a, const vector<int>b) {
	int an = a.size(), bn = b.size();
	if (an < bn)
		return karatsuba(b, a);
	
	if (an == 0 || bn == 0)
		return vector<int>();

	if (an <= 50)
		return multiply(a, b);

	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin()+half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(),half));
	vector<int> b1(b.begin() + min<int>(b.size(), half),b.end());
	vector<int> z2 = karatsuba(a1,b1);
	vector<int> z0= karatsuba(a0, b0);
	addTo(a0, a1, 0); addTo(b0, b1, 0);
	
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector <int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half+half);
	return ret;
}
int main() {
	vector<int> a;
	vector<int> b;
	string A;
	string B;
	cin >> A >> B;
	for (int i = A.size() - 1; i >= 0; i--)
		a.push_back(A[i]-'0');
	for (int i = B.size() - 1; i >= 0; i--)
		b.push_back(B[i]-'0');
	vector<int> c = karatsuba(a,b);

	int cSize = c.size();
	for (int i = cSize-1; i >=0; i--)
		cout << c[i];

	return 0;
}