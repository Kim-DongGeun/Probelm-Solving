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


int n, m, t, h;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

bool check[32][12] = { false };
int ans = 4;


bool go() {
    for (int j = 1; j <= n; j++) {
        int cur = j;
        for (int i = 1; i <= h; i++) {
            if (check[i][cur]) cur = cur + 1;
            else if (check[i][cur - 1]) cur = cur - 1;
        }
        if (j != cur) return false;
    }
    return true;
}

void draw(int height, int cur) {
    if (go()) {
        ans = min(ans, cur);
        return;
    }

    for (int i = height; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (check[i][j]) continue;
            else if (check[i][j - 1]) continue;
            else if (check[i][j + 1]) continue;
            else if (cur < 3) {
                check[i][j] = true;
                draw(i, cur + 1);
                check[i][j] = false;
            }
        }
    }
}

void Input() {
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        check[x][y] = true;
    }
}

void solve() {
    draw(1, 0);
    if (ans != 4) cout << ans;
    else cout << -1;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    Input();
    solve();

    return 0;
}


