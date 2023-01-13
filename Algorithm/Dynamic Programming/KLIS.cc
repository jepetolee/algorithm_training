#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;


const int MAX = 200000000 +1;
int N,K;
int Numbers[500];
int cacheLen[501],cacheCnt[501];

int LIS(int start){
    int &ret = cacheLen[start+1];
    if(ret != -1)return ret;
    ret=1;
    for(int next =start+1;next<N; next++)
        if(start==-1 || Numbers[start]<Numbers[next])
          ret = max(ret,LIS(next)+1);
    return ret;
}

int Count(int start){
    if(LIS(start)==1) return 1;
    int &ret = cacheCnt[start+1];
    if(ret != -1)return ret;
    ret= 0;
    for(int next =start +1;next<N;next++){
        if((start==-1 ||Numbers[start]<Numbers[next])&&LIS(start = LIS(next)+1))
          ret = min<long long> (MAX,(long long)ret+ Count(next));
    }
    return ret;
}
void reconstruct(int start, int skip,vector<int>&lis){
    if(start !=-1) lis.push_back(Numbers[start]);

    vector<pair<int,int>> followers;
    for(int next= start +1;next<N; next++) {
        if((start == -1 || Numbers[start] <Numbers[next])&&LIS(start)== LIS(next)+1)
        followers.push_back(make_pair(Numbers[next],next));
    }
    sort(followers.begin(),followers.end());
    for(int i=0; i<followers.size();i++){
        int idx = followers[i].second;
        int cnt = Count(idx);
        if(cnt <=skip)
        skip -= cnt;
        else{
            reconstruct(idx,skip,lis);
            break;
        }
    }
}

int main(void){
    FASTIO;
    int TestCase;
    cin>> TestCase;
    while(TestCase--){
        cin >> N >> K;
        memset(cacheLen, -1, sizeof(cacheLen));
		memset(cacheCnt, -1, sizeof(cacheCnt));
        for (int i=0;i<N; i++) cin >> Numbers[i];
        cout << LIS(-1) - 1 << endl;
		vector<int> Answer;
		reconstruct(-1, K - 1, Answer);
		for (int i = 0; i < Answer.size(); i++)
			cout << Answer[i] << " ";
		cout << endl;


    }
}