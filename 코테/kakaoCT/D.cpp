#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e12;
long long  D[201][201];
int Next[201][201];


void solve(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}

vector<int> Path(int start, int end) {
    if (Next[start][end] == -1) return {};

    vector<int> path = { start };
    while (start != end) {
        start = Next[start][end];
        path.push_back(start);
    }
    return path;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = INF;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) D[i][j] = 0;
            else D[i][j] = INF;
            Next[i][j] = -1;
        }
    }

    for (int i = 0; i < fares.size(); i++) {
        D[fares[i][0]][fares[i][1]] = fares[i][2];
        D[fares[i][1]][fares[i][0]] = fares[i][2];
        Next[fares[i][0]][fares[i][1]] = fares[i][1];
        Next[fares[i][1]][fares[i][0]] = fares[i][0];
    }

    solve(n);

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = D[i][a] + D[i][b] + D[i][s];
        answer = min(answer, sum);
    }

    vector<int> pathA, pathB;
    pathA = Path(s, a);
    pathB = Path(s, b);

    
    int idx = 1;
    int minus = 0;
    while (idx < pathA.size() && idx < pathB.size() && pathA[idx] == pathB[idx]) {
        minus += D[pathA[idx - 1]][pathA[idx]];
        idx++;
    }

    answer = min(answer, D[s][a] + D[s][b] - minus);

    return (int)answer;
}

void solve() {
    solution(6,4,2,3,{ {2, 6, 6} ,{6, 3, 7},{4, 6, 7},{6, 5, 11},{2, 5, 1},{5, 3,1},{2, 4, 1},{4, 3, 9} });
}

int main() {
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}