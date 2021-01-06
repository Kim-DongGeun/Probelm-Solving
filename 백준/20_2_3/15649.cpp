#include <iostream>
#include <vector>
using namespace std;

int arr[9];
bool check[9] = { false, };
int N, M;

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			arr[depth] = i + 1;
			dfs(depth + 1);
			check[i] = false;
		}
	}

}

int main() {
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		check[i] = true;
		arr[0] = i + 1;
		dfs(1);
		check[i] = false;
	}


	return 0;
}