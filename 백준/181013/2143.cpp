/*
	idea :�����ϴ� �κм����� ���α��ؼ� ���� T�� �Ǵ� ��츦 ��� ã�´�.
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