#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int n;
		int arr[201];
		bool check[201];

		memset(arr, 0, sizeof(arr));
		memset(check, false, sizeof(check));

		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i += 2) {
			scanf("%d", &arr[i]);
			check[arr[i]] = true;
		}

		int sum = 2 * n * (2 * n + 1) / 2;
		for (int i = 1; i <= 2 * n; i += 2) {
			for (int j = 2; j <= 2 * n; j++) {
				if (!check[j] && arr[i] < j) {
					arr[i + 1] = j;
					check[j] = true;
					break;
				}
			}
			sum -= (arr[i] + arr[i+1]);
		}

		if (!sum) {
			for (int i = 1; i <= 2 * n; i++)
				printf("%d ", arr[i]);
			printf("\n");
		}
		else printf("-1\n");

	}
	return 0;
}