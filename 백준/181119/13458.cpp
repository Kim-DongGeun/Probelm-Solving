#include <iostream>
#include <vector>
using namespace std;



int main()
{
	int N;
	scanf("%d", &N);

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int B, C;
	scanf("%d %d", &B, &C);

	long long ans = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] >= B) {
			arr[i] -= B;
		}
		else
		{
			arr[i] = 0;
		}
		ans++;
	}

	for (int i = 0; i < N; i++) {
		ans += arr[i] / C;
		arr[i] % C != 0 ? ans++ : ans;
	}

	printf("%lld\n", ans);
	return 0;
}