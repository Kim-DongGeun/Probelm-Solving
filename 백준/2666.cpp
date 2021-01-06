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


int n, m, t, k;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

int arr[21];
int dp[22][22][22] = { 0, };

int dfs(int depth, int left, int right) {
    if (depth == m + 1) {
        return 0;
    }

    int& ret = dp[depth][left][right];
    if (ret != -1) return ret;

    ret = 0;

    ret += min(dfs(depth + 1, arr[depth], right) + abs(left - arr[depth]), dfs(depth + 1, left, arr[depth]) + abs(right - arr[depth]));

    return ret;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int L, R;

    cin >> n >> L >> R >> m;
    for (int i = 1; i <= m; i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));

    cout << dfs(1, L, R);


    return 0;
}


