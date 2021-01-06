#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_INDEX 8005

int d;
string str1, str2;
int pos[MAX_INDEX], sa[MAX_INDEX];
int lcp[MAX_INDEX] = { 0 };
bool check[MAX_INDEX] = { false };

bool cmp(int i, int j) {
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	else return pos[i + d] < pos[j + d];
}

int main() {
	cin >> str1 >> str2;
	string str = str1 + "#" + str2;
	int N = str.length();
	int cnt = str1.length() < str2.length() ? str1.length() : str2.length();

	for (int i = 0; i < N; i++) {
		sa[i] = i; // 처음 인덱스
		pos[i] = str[i]; // 처음에는 각자리 문자
	}

	for (d = 1;; d *= 2) {
		sort(sa, sa + N, cmp);

		int temp[MAX_INDEX] = { 0 };
		for (int i = 0; i < N - 1; i++)
			temp[i + 1] = temp[i] + cmp(sa[i], sa[i + 1]);
		for (int i = 0; i < N; i++)
			pos[sa[i]] = temp[i];

		if (temp[N - 1] == N - 1) break;
	}

	int len = 0;
	for (int i = 0; i < N; i++) {
		int k = pos[i];
		if (k) {
			int j = sa[k - 1];
			if ((i < str1.length() && j < str2.length()) || (i > str1.length() && j > str2.length())) check[k] = true;
			while ((i + len < N && j + len < N) && str[i + len] == str[j + len]) {
				len++;
			}
			lcp[k] = len;
			if (len) len--;
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		if(!check[i])
			ans = max(ans, min(cnt, lcp[i]));
	cout << ans << '\n';
	return 0;
}
