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

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	map<long long, long long> dp;

	for (int i = 0; i < room_number.size(); i++) {
		if (dp.count(room_number[i]) == 0) {
			dp[room_number[i]] = room_number[i] + 1;
			answer.push_back(room_number[i]);
		}
		else {
			long long cur = room_number[i];
			vector<long long> v;
			while (dp.count(dp[cur]) != 0) {
				v.push_back(cur);
				cur = dp[cur];
			}
			for (int i = 0; i < v.size(); i++) {
				dp[v[i]] = cur + 1;
			}
			cur = dp[cur];
			dp[cur] = cur + 1;
			answer.push_back(cur);
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


	return 0;
}

