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

string p;

vector<string> Split(string str) {
	vector<string> temp;
	pair<int, int> cnt = { 0,0 };
	for (int i = 0; i < str.length(); i++) {
		str[i] == '(' ? cnt.first++ : cnt.second++;
		if (cnt.first == cnt.second) {
			temp.push_back(str.substr(0, cnt.first + cnt.second));
			temp.push_back(str.substr(cnt.first + cnt.second));
			break;
		}
	}
	return temp;
}

bool RightWords(string str) {
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (s.empty()) {
			s.push(str[i]);
			if (s.top() == ')') return false;
		}
		else {
			if (s.top() == str[i]) s.push(str[i]);
			else s.pop();
		}
	}
	if (s.empty()) return true;
	else return false;
}

string go(string p) {

	if (p == "") return p;
	vector<string> words = Split(p);
	string u = words[0];
	string v = words[1];

	if (RightWords(u)) {
		u += go(v);
	}
	else {
		string temp = "(";
		temp += go(v);
		temp += ")";
		for (int i = 1; i < u.size() - 1; i++) {
			if (u[i] == '(') temp += ')';
			else temp += '(';
		}
		return temp;
	}
	return u;
}

void solve() {
	cin >> p;
	string ans = "";
	ans = go(p);
	cout << ans;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	solve();
	return 0;
}
