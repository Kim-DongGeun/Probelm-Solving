#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int arr[9] = { 9,90,900,9000,90000,900000,9000000,90000000,900000000 };
	int N;
	scanf_s("%d", &N);

	int temp = N;
	int cnt = 0;
	while (temp > 0) {
		temp /= 10;
		cnt++;
	}

	long long ans = 0;
	for (int i = 1; i < cnt; i++) {
		ans += (long long)arr[i - 1] * i;
	}
	ans += (long long)(N - pow(10, (cnt - 1)) + 1) * cnt;
	printf("%lld\n", ans);

	return 0;
}