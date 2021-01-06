#include <iostream>
using namespace std;

char Map[51][51];

int main() {
	int N, ans = 0;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];

	for (int i = 0; i < N; i++) {
		bool check[51] = { false, };
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (Map[i][j] == 'Y') {
				check[j] = true;
				for (int k = 0; k < N; k++) {
					if (Map[j][k] == 'Y' && i != k) check[k] = true;
				}
			}
		}
		for (int k = 0; k < N; k++) {
			if (check[k]) count++;
		}
		ans = ans < count ? count : ans;
	}

	printf("%d\n", ans);
	return 0;
}