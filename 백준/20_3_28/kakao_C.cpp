#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <set>
using namespace std;

typedef long long ll;

void solve() {

}

int n;
map<string, int> m;
vector<string> v[9];
set<string> s;

void dfs(int d) {
	if (d == n) {
		string cur = "";
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			cur += (*iter).first;
		}
		s.insert(cur);
		//answer++;
		return;
	}


	for (int i = 0; i < v[d].size(); i++) {
		if (m.count(v[d][i]) == 0) {
			m[v[d][i]] = 1;
			dfs(d + 1);
			m.erase(v[d][i]);
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;	
	n = banned_id.size();
	for (int i = 0; i < user_id.size(); i++) {
		for (int j = 0; j < banned_id.size(); j++) {
			if (user_id[i].length() == banned_id[j].length()) {
				bool out = true;
				for (int k = 0; k < user_id[i].length(); k++) {
					if (banned_id[j][k] == '*') continue;
					else if (banned_id[j][k] != user_id[i][k]) {
						out = false;
						break;
					}
				}
				if (out)v[j].push_back(user_id[i]);
			}
		}
	}

	dfs(0);

	answer = s.size();
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
	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };
	cout << solution(user_id, banned_id);

	return 0;
}

