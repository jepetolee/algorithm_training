/*
  ID : BOGGLE
  USING METHOD : Brute Force
*/
#include <stdc++.h>
 
using namespace std;

char board[5][5]; // 보드판의 크기

// 선택한 주위 8칸을 기점으로 돌면서 탐색
const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };

string words[100];

// 단어를 찾는 함수
bool checkword(int x, int y, const string & word) {
  if (y < 0 || y >= 5 || x < 0 || x >= 5) return false;
  if (board[y][x] != word[0]) return false;
  if (word.size() == 1) return true;
  for (int direction=0; direction < 8; ++direction) {
	  if (checkword(x + dx[direction], y + dy[direction], word.substr(1)))
		  return true;
  }
  return false;
}

//메인 실행
int main() {
	int testcase;
	int wordcase;
	cin >> testcase;
    
	for (int count = 0; count < testcase; count++) {
		
		for (int x = 0; x < 5; x++)
			for (int y = 0; y < 5; y++)
				cin >> board[x][y];
		cin >> wordcase;
		for (int i = 0; i < wordcase; i++) cin >> words[i];

		for (int i = 0; i < wordcase; i++) {
			bool result;
			for (int y = 0; y < 5; y++) {
				result = 0;
	
				for (int x = 0; x < 5; x++) 
					if (result = checkword(x,y,words[i])) break;
	
				if (result) break;

			}

			cout << words[i] << (bool)result << endl;
		}
		
	}

}