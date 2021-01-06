/*
	idea :연속하는 부분수열을 전부구해서 합이 T가 되는 경우를 모두 찾는다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	int N;
	scanf("%d", &N);
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int M;
	scanf("%d", &M);
	vector<int> B(M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}

	vector<int> a;
	vector<int> b;

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			a.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++) {
		int sum = 0;
		for (int j = i; j < M; j++) {
			sum += B[j];
			b.push_back(sum);
		}
	}

	sort(b.begin(), b.end());

	long long ans = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int target = T - a[i];
		auto lo = lower_bound(b.begin(), b.end(), target);
		auto hi = upper_bound(b.begin(), b.end(), target);
		ans += hi - lo;
	}

	printf("%lld\n", ans);
	return 0;
}