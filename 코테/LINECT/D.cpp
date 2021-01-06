#include <string>
#include <vector>

using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };


int solution(vector<vector<int>> maze) {
    int answer = 0;
    int curDir = maze[0][1] == 1 ? 3 : 0;
    int r = 0, c = 0, n = maze.size();
    while (r != n - 1 || c != n - 1) {
        int nx = c + dx[(curDir + 1) % 4];
        int ny = r + dy[(curDir + 1) % 4];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || maze[ny][nx] == 1) { // 왼쪽이 벽일 때
            nx = c + dx[curDir];
            ny = r + dy[curDir];
            while (nx < 0 || ny < 0 || nx >= n || ny >= n || maze[ny][nx] == 1) { // 앞으로 갈 수 없으면
                curDir = (curDir + 3) % 4;
                nx = c + dx[curDir];
                ny = r + dy[curDir];
            }
            r = ny; c = nx; // 전진
            answer++;
        }
        else { // 왼쪽으로 돌아서 전진
            curDir = (curDir + 1) % 4;
            c += dx[curDir];
            r += dy[curDir];
            answer++;
        }
        
    }

    return answer;
}
void solve() {
    solution({{0, 1, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 1, 0}, {0, 1, 1, 1, 1, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0}} );
}

int main() {
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
