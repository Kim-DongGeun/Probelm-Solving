#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

typedef long long ll;

void solve() {

}

int solution(vector<int> stones, int k) {
    int answer = 200000001;

    for (int i = 0; i + k <= stones.size();) {
        int MAX = 0;
        int cnt;
        for (int j = 0; j < k; j++) {
            if (MAX < stones[i + j]) {
                cnt = j;
                MAX = stones[i + j];
            }
        }
        if (answer > MAX) {
            answer = MAX;
        }

        i += cnt + 1;
        int prev = stones[i];
        int idx = i + 1;
        while (stones.size() > idx && prev > stones[idx]) {
            prev = stones[idx++];
        }
        if (idx - i > k) {
            i = idx - k;
        }
    }

    return answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	//solve();
	/*cin >> t;
	while (t--) {
		solve();
	}*/
    vector<int> stones;
    for (int i = 200000; i >= 1; i--) stones.push_back(i);
    cout << solution(stones, 100000);

	return 0;
}

