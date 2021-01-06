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
vector<int> solution(string s) {
	vector<int> answer;

	vector<int> v[501];

	int N = s.length();
	int index = 1;
	int cnt = 0;
	while (index < N) {
		int value = 0;
		while (index < N - 1) {
			if (s[index] == '{');
			else if (s[index] == '}') {
				v[cnt].push_back(value);
				index += 2;
				break;
			}
			else if (s[index] != ',') {
				value = value * 10 + ((s[index]) - '0');
			}
			else if (s[index] == ',') {
				v[cnt].push_back(value);
				value = 0;
			}
			index++;
		}
		cnt++;
	}

	bool check[501] = { false, };
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (v[j].size() == i + 1) {
				for (int k = 0; k < i + 1; k++) {
					if (!check[v[j][k]]) {
						check[v[j][k]] = true;
						answer.push_back(v[j][k]);
					}
				}
			}
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
	solution("{{20,111},{111}}");
	return 0;
}

