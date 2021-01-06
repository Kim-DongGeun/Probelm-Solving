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

int arr[100001];

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    long long ans = 1e18;
    int K = (int)pow(arr[n - 1], (1.0 / (n - 1))) + 1;
    long long prev = 1e18;
    for (int i = 1; i <= K; i++) {
        long long cnt = 0;
        bool flag = false;
        for (int j = 0; j < n; j++) {
            cnt += abs(arr[j] - pow(i, j));
            if (cnt > prev) {
                ans = prev;
                flag = true;
                break;
            }
        }
        if (flag) break;
        prev = cnt;
        ans = min(ans, cnt);
    }

    cout << ans;

    return 0;
}


