#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		printf("1\n");
		return 0;
	}

	int k = 2;
	int index = 1;
	while (true) {
		if (k <= N && N < k + 6 * index) {
			printf("%d\n", index + 1);
			break;
		}
		k += 6 * index;
		index++;
	}
	return 0;
}