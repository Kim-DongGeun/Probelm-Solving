//2410
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
const int INF = 1e9;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

int dp[1000000] = { 0, };

void Input() {
    cin >> n;
}
void solve() {
    int i = 0;
    dp[0] = 1;
    for (; pow(2, i) <= n; i++) {
        for (int j = (int)pow(2, i); j <= n; j++) {
            dp[j] = (dp[j] + dp[j - (int)pow(2, i)]) % INF;
        }
    }
    cout << dp[n];
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    Input();
    solve();

    return 0;
}




