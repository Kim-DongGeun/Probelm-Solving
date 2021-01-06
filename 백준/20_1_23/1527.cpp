#include <iostream>
using namespace std;

int A, B;

int dfs(int value, int depth) {
	if (depth >= 10 || value > B) return 0;
	int ans = 0;

	if (value >= A) ans++;

	ans += dfs(value * 10 + 4, depth + 1);
	ans += dfs(value * 10 + 7, depth + 1);

	return ans;
}

int main() {
	cin >> A >> B;

	printf("%d\n", dfs(0,0));
	return 0;
}