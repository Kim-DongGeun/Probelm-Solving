#include <iostream>
using namespace std;

int num;

bool dfs(int depth, int cur) {
	if (depth == 3) {
		if (cur == 0) return true;
		return false;
	}

	int n = 1;
	bool check = false;
	while (true) {
		int value = (n * (n + 1)) / 2;
		if (value <= cur) {
			check = dfs(depth + 1, cur - value);
		}
		else
			break;

		if (check)
			break;
		n++;
	}
	return check;
}

int main() {
	int K;
	scanf_s("%d", &K);


	for (int i = 0; i < K; i++) {
		scanf_s("%d", &num);

		if (dfs(0, num))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}