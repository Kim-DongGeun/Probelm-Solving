#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int d, N;
vector<int> pos;
vector<int> sa;
vector<int> lcp;
vector<string> seek;

bool cmp(int i, int j) {
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	else return (i + d < N && j + d < N) ? pos[i + d] < pos[j + d] : i < j;
}

int main() {

	int n;
	string target;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> target;
		seek.push_back(target);
	}
	int Q;
	cin >> Q;
	for (int j = 0; j < Q; j++) {
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
		bool found;
		bool include = false;
		for (int k = 0; k < n; k++) {
			int start = 0;
			int end = str.length() - 1;
			found = true;
			while (start <= end) {
				int mid = (start + end) / 2;
				if (str[mid] < seek[k][0]) {
					start = mid + 1;
				}
				else if (str[mid] >= seek[k][0]) {
					end = mid - 1;
					if (str[mid] == seek[k][0]) {
						for (int i = 0; i < seek[k].length(); i++) {
							if (seek[k][i] != str[mid + i]) {
								found = false;
								break;
							}
						}
						if (found) {
							cout << "YES\n";
							include = true;
							break;
						}
					}
				}
			}
		}
		if (!include) cout << "NO\n";
		
	}
	return 0;
}
