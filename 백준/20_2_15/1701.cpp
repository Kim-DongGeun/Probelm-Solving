#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int d, N;
vector<int> pos;
vector<int> sa;
vector<int> lcp;

bool cmp(int i, int j) {
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	else return (i + d < N && j + d < N) ? pos[i + d] < pos[j + d] : i < j;
}

int main() {
	string str;
	cin >> str;

	N = (int)str.length();
	pos.resize(N + 1);
	sa.resize(N);
	lcp.resize(N);

	for (int i = 0; i < N; i++) {
		sa[i] = i; // 처음 인덱스
		pos[i] = str[i]; // 처음에는 각자리 문자
	}

	for (d = 1;; d *= 2) {
		sort(sa.begin(), sa.end(), cmp);

		vector<int> temp(N + 1, 0);
		for (int i = 0; i < N - 1; i++)
			temp[i + 1] = temp[i] + cmp(sa[i], sa[i + 1]);
		for (int i = 0; i < N; i++)
			pos[sa[i]] = temp[i];

		if (temp[N - 1] == N - 1) break;
	}

	int len = 0;
	for (int i = 0; i < N; i++)
		pos[sa[i]] = i;
	for (int i = 0; i < N; i++) {
		int k = pos[i];
		if (k) {
			int j = sa[k - 1];
			while ((i + len < N && j + len < N) && str[i + len] == str[j + len]) len++;
			lcp[k] = len;
			if (len) len--;
		}
	}

	int ans = 0;
	for (int i = 0; i < N - 1; i++)
		ans = max(ans, lcp[i]);
	cout << ans << '\n';
	return 0;
}
