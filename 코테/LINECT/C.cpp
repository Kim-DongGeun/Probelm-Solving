#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
int ans = 11;
int value = 0;

void dfs(int n, int depth, int cur, int cnt) {
    if (depth == n) {
        if (ans > cnt && cur / 10 == 0) {
            ans = cnt;
            value = cur;
        }
        return;
    }


    int idx = 0;
    int temp = cur;
    while (temp > 0) {
        idx++;
        temp /= 10;
    }

    for (int i = 1; i < idx; i++) {
        int a = cur / (int)pow(10, i);
        int b = cur % (int)pow(10, i);
        dfs(n, depth + 1, a + b, cnt + 1);
    }

}

vector<int> solution(int n) {
    vector<int> answer;

    int cnt = 0;
    int temp = n;
    while (temp > 0) {
        cnt++;
        temp /= 10;
    }

    dfs(cnt - 1, 0, n, 0);
    answer = { ans, value };

    return answer;
}
void solve() {
    solution(1000000000);
}

int main() {
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
