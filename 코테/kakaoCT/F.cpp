#include <string>
#include <vector>

using namespace std;

int Ans = 1e9;
vector<vector<int>> Board;
bool check[4][4] = { false };

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

int dp[2][4][4][6][6];

int dfs(bool enter, int r, int c, int cnt, int pictureCnt, int picture) {
    if (pictureCnt == 0) {
        return 1;
    }

    int& ret = dp[enter][r][c][pictureCnt][picture];
    if (ret != -1) return ret;

    ret = 0;

    if (!enter && Board[r][c] != 0 && !check[r][c]) {
        check[r][c] = true;
        ret = min(ret, dfs(true, r, c, cnt + 1, pictureCnt, Board[r][c])) + 1;
        check[r][c] = false;
    }
    if (enter && Board[r][c] == picture && !check[r][c]) {
        check[r][c] = true;
        ret = min(ret, dfs(false, r, c, cnt + 1, pictureCnt - 1, 0)) + 1;
        check[r][c] = false;
    }
    for (int i = 0; i < 4; i++) {
        int nr = r + dy[i];
        int nc = c + dx[i];
        if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4) continue;
        ret = min(ret, dfs(enter, nr, nc, cnt + 1, pictureCnt, picture)) + 1;
    }

    for (int i = 0; i < 4; i++) {
        int nr = r + dy[i];
        int nc = c + dx[i];

        while (true) {
            if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4 || Board[nr][nc] != 0) break;
            nr += dy[i];
            nc += dx[i];
        }
        if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4) {
            nr -= dy[i];
            nc -= dx[i];
        }
        ret = min(ret, dfs(enter, nr, nc, cnt + 1, pictureCnt, picture)) + 1;
    }
    return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    Board = board;

    int cnt = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] != 0) cnt++;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                for (int t = 0; t < 6; t++)
                    for (int a = 0; a < 6; a++) dp[i][j][k][t][a] = -1;

    cnt /= 2;

    answer = dfs(false, r, c, 0, cnt, 0);

    return answer;
}

void solve() {
    solution({{1, 0, 0, 3}, {2, 0, 0, 0}, {0, 0, 0, 2}, {3, 0, 1, 0}}, 1,0 );
}

int main() {
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}