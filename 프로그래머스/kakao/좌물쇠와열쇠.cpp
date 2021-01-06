#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m, t, h, k;
const int INF = 1e9;

const int dx[8] = { 1, 1,0,-1, -1, -1,0, 1 };
const int dy[8] = { 0,-1, -1, -1,0,1,1,1 };

vector<vector<int>> arr(60, vector<int>(60, -1));

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int n = lock.size();
    int m = key.size();

    int homeCnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (lock[i][j] == 0) homeCnt++;

    if (homeCnt == 0) return true;

    for (int i = 0; i < n; i++) { // lock 재배치
        for (int j = 0; j < n; j++) {
            arr[m - 1 + i][m - 1 + j] = lock[i][j];
        }
    }
    int C = 4;
    while (C--) {
        for (int r = 0; r < n + m - 1; r++) { // 슬라이드 이동
            for (int c = 0; c < n + m - 1; c++) {
                int cnt = 0;
                bool match = true;
                for (int i = 0; i < m; i++) { // m x m 검사
                    for (int j = 0; j < m; j++) {
                        if (arr[i + r][j + c] == -1) continue;
                        if (arr[i + r][j + c] == 1 && key[i][j] == 1) match = false;
                        else if (arr[i + r][j + c] == 0 && key[i][j] == 1) {
                            match = true;
                            cnt++;
                        }
                        if (!match) break;
                    }
                    if (!match) break;
                }
                if (homeCnt == cnt && match) return true;
            }
        }
        // key 회전
        vector<vector<int>> temp = key;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                key[i][j] = temp[j][m - i - 1];
            }
        }
    }
    return answer;
}


void solve() {
	
    cout << solution({ {1,1,1},{1,0,1},{1,1,1} }, { {0,0,0}, {0,0,0},{0,0,0} });
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	solve();
	return 0;
}
