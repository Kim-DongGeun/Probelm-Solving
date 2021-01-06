#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int d, N;
vector<int> pos;

bool cmp(int i, int j) {
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	else return (i + d < N && j + d < N) ? pos[i + d] < pos[j + d] : i > j;
}

int main() {
	string str;
	cin >> str;
	N = str.length();
	vector<int> sa(N);
	pos.resize(N + 1);

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

	vector<int> lcp(N);
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

	for (int i = 0; i < N; i++)
		printf("%d ", sa[i] + 1);
	printf("\n");
	for (int i = 0; i < N; i++) {
		if (i == 0) printf("x ");
		else printf("%d ", lcp[i]);
	}

	return 0;
}
