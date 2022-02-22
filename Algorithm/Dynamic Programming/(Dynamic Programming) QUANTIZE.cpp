#include <iostream>
#include <algorithm>
using namespace std;
int Length, S[100], PartialSum[101], PartialSquareSum[101];
const int INF = 99999999;

void Preprocess()
{
	sort(S, S + Length);
	PartialSum[0] = S[0];
	PartialSquareSum[0] = S[0] * S[0];
	for (int i = 1; i < Length; ++i)
	{
		PartialSum[i] = PartialSum[i - 1] + S[i];
		PartialSquareSum[i] = PartialSquareSum[i - 1] + S[i] * S[i];
	}
}
int Minor_Error(int Low, int High)
{
	int Sum = PartialSum[High] - (Low == 0 ? 0 : PartialSum[Low - 1]);
	int SquareSum = PartialSquareSum[High] - (Low == 0 ? 0 : PartialSquareSum[Low - 1]);
	int Mean = int(0.5 + (double)Sum / (High - Low + 1));
	int Result = SquareSum - 2 * Mean * Sum + Mean * Mean * (High - Low + 1);
	return Result;
}

int Cache[101][11];

int Quantization(int From, int Parts)
{
	if (From == Length)
		return 0;
	if (Parts == 0)
		return INF;
	int &Result = Cache[From][Parts];
	if (Result != -1)
		return Result;
	Result = INF;
	for (int partSize = 1; From + partSize <= Length; ++partSize)
		Result = min(Result, Minor_Error(From, From + partSize - 1) + Quantization(From + partSize, Parts - 1));
	return Result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int TestCase;
	cin >> TestCase;
	while (TestCase--)
	{
		fill(&PartialSquareSum[0], &PartialSquareSum[100], 0);
		fill(&PartialSum[0], &PartialSum[100], 0);
		fill(&Cache[0][0], &Cache[100][10], -1);
		int Parts;
		cin >> Length >> Parts;
		for (int i = 0; i < Length; i++)
			cin >> S[i];
		// sorting the list(S), and make some squared summination list and summination list
		Preprocess();
		cout << Quantization(0, Parts) << "\n";
	}
}