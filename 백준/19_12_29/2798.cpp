#include <iostream>
using namespace std;

int main() {
	int N, M;
	int arr[101];
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &arr[i]);
	}

	int MAX = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = arr[i] + arr[j] + arr[k];
				if (sum <= M && MAX < sum)
					MAX = sum;
			}
		}
	}
	printf("%d\n", MAX);
	return 0;
}