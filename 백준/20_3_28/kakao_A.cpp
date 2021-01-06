#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

typedef long long ll;

void solve() {

}
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;
	int n = board.size();
	for (int i = 0; i < moves.size(); i++) {
		int idx = 0;
		while (idx < n && board[idx][moves[i] - 1] == 0) idx++;
		if (idx == n) continue;
		if (s.size() >= 1 && s.top() == board[idx][moves[i] - 1]) {
			s.pop();
			answer += 2;
		}
		else s.push(board[idx][moves[i] - 1]);
		board[idx][moves[i] - 1] = 0;
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	//solve();
	/*cin >> t;
	while (t--) {
		solve();
	}*/
	vector<vector<int>> board = { {0,0,0,0,0}, {0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	cout << solution(board, moves);
	return 0;
}

