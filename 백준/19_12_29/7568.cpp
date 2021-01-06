#include <iostream>
using namespace std;

int main() {
	int N, arr[51][2];

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &arr[i][0], &arr[i][1]);
	}


	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
				count++;
		}
		printf("%d ", count + 1);
	}
	return 0;
}