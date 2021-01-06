#include <iostream>
#include <string>
using namespace std;


int Arr[200001][26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		int arr[26] = { 0, };
		int order;
		string str;
		cin >> n >> m;
		cin >> str;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				Arr[i + 1][j] = Arr[i][j];
			}
			Arr[i + 1][str[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++)
			arr[i] = Arr[n][i];


		for (int i = 0; i < m; i++) {
			cin >> order;
			for (int j = 0; j < 26; j++) {
				arr[j] += Arr[order][j];
			}
		}

		for (int i = 0; i < 26; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	return 0;
}