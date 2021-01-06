#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	int arr[101][101];

	cin >> n >> m;
	for(int i = 0 ; i < n; i++)
		for (int j = 0; j < n; j++) {
			arr[i][j] = INF;
			if (i == j) arr[i][j] = 0;
		}
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		if (arr[u - 1][v - 1] != INF) arr[u - 1][v - 1] = min(arr[u - 1][v - 1], w);
		else arr[u - 1][v - 1] = w;
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == INF) printf("0 ");
			else printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}