#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int arr[21][21];
	bool check[21][21];
	memset(check, true, sizeof(check));


	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (i == j || j == k || k == i) continue;
				if (arr[i][j] == arr[i][k] + arr[k][j]) {
					check[i][j] = false;
				}
				else if (arr[i][j] > arr[i][k] + arr[k][j]) {
					cout << "-1\n";
					return 0;
				}
			}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if(check[i][j])
				ans += arr[i][j];
		}
	}

	cout << ans << '\n';
	return 0;
}