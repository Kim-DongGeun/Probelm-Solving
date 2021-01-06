#include <iostream>
using namespace std;

int N, R, G, B;
long long ans = 0;

int F(int N) {
	if (N == 0) return 1;
	int num = 1;
	for (int i = 1; i <= N; i++)
		num *= i;
	return num;
}

long long cal(int depth, int R, int G, int B) {
	return (long long)(F(depth) / F(R) * F(G) * F(B));
}

void dfs(int depth, int R, int G, int B, long long cnt) {
	if (depth > N) {
		ans += cnt;
		return;
	}

	if (depth % 1 == 0) {
		if (R >= depth)
			dfs(depth + 1, R - depth, G, B, cnt);
		if (G >= depth)
			dfs(depth + 1, R, G - depth, B, cnt);
		if (B >= depth)
			dfs(depth + 1, R, G, B - depth, cnt);
	}

	if (depth % 2 == 0) {
		if (R >= depth / 2 && G >= depth / 2)
			dfs(depth + 1, R - depth / 2, G - depth / 2, B, cnt * cal(depth, depth / 2, depth / 2, 0));
		if (R >= depth / 2 && B >= depth / 2)
			dfs(depth + 1, R - depth / 2, G, B - depth / 2, cnt * cal(depth, depth / 2, 0, depth / 2));
		if (B >= depth / 2 && G >= depth / 2)
			dfs(depth + 1, R, G - depth / 2, B - depth / 2, cnt * cal(depth, 0, depth / 2, depth / 2));
	}

	if (depth % 3 == 0) {
		if (R >= depth / 3 && G >= depth / 3 && B >= depth / 3)
			dfs(depth + 1, R - depth / 3, G - depth / 3, B - depth / 3, cnt * cal(depth, depth / 3, depth / 3, depth / 3));
	}

}

int main() {
	scanf_s("%d %d %d %d", &N, &R, &G, &B);

	if (N == 0) {
		printf("0"); return 0;
	}
	dfs(1, R, G, B, 1);

	printf("%lld\n", ans);
	return 0;
}