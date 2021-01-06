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

int n, m, t, h, k;
const int INF = 1e9;

const int dx[8] = { 1, 1,0,-1, -1, -1,0, 1 };
const int dy[8] = { 0,-1, -1, -1,0,1,1,1 };
string x;

vector<string> Split(int len) {
	vector<string> temp;
	for (int i = 0; i < x.length(); i += len) {
		string str = x.substr(i, len);
		temp.push_back(str);
	}
	return temp;
}


void solve() {
	cin >> x;
	int ans = 1001;
	for (int i = 1; i <= (int)x.length() / 2; i++) {
		vector<string> words = Split(i);
		int len = words.size();
		words.push_back("");
		string str = "";
		bool last = false;

		int j = 0;
		for (; j < len;) {
			if (words[j].compare(words[j+1]) == 0) {
				int idx = j + 1;
				while (idx + 1 < (int)words.size() && words[idx].compare(words[idx+1]) == 0)
					idx++;
				str += to_string(idx - j + 1) + words[j];
				j = idx + 1;
			}
			else {
				str += words[j];
				j++;
			}
		}
		ans = min(ans, (int)str.length());
	}
	if (ans == 1001) cout << 1;
	else cout << ans;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	solve();
	return 0;
}
