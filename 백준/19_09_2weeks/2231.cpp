#include <iostream>
using namespace std;

int main() {
	int N;
	scanf_s("%d", &N);

	int temp = N;
	int count = 0;
	while (temp > 0) {
		count++;
		temp /= 10;
	}

	bool check = true;
	for (int i = 0 > N - 9 * count ? 0 : N - 9 * count; i < N; i++) {
		int sum = 0;
		temp = i;
		sum = temp;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == N) {
			printf("%d\n", i);
			check = false;
			break;
		}
	}
	if (check) printf("%d\n", 0);

	return 0;
}