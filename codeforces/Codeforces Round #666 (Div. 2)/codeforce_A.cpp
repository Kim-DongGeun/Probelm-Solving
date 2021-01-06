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


int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int check[27];
        for (int i = 0; i < 27; i++) check[i] = 0;
        for (int i = 0; i < n; i++) {
            string x;
            cin >> x;
            for (int i = 0; i < x.length(); i++) {
                check[x[i] - 'a']++;
            }
        }
        bool out = false;
        for (int i = 0; i < 27; i++) {
            if (check[i] % n != 0) {
                out = true;
                break;
            }
        }
        if (out) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
