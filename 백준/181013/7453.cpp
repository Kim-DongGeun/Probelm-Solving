/*
	idea : �׳� �������� ������ n^4�̹Ƿ� �ð��ʰ� �迭 �ΰ��� �������� ������ �ΰ��� ���� ���ؼ� �̺�Ž������ ã�´�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<long long> A(N);
	vector<long long> B(N);
	vector<long long> C(N);
	vector<long long> D(N);

	for (int i = 0; i < N; i++)
		scanf("%lld %lld %lld %lld", &A[i], &B[i], &C[i], &D[i]);

	vector<long long>sumCD(N*N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sumCD[i * N + j] = C[i] + D[j];

	sort(A.begin(), A.end());
	sort(A.begin(), A.end());
	sort(sumCD.begin(), sumCD.end());

	long long ans = 0;
	for(int i = 0 ; i< N ;i++)
		for (int j = 0; j < N; j++)
		{
			long long sum = A[i] + B[j];
			auto lo = lower_bound(sumCD.begin(), sumCD.end(), -sum);
			auto hi = upper_bound(sumCD.begin(), sumCD.end(), -sum);
			ans += hi - lo;
		}

	printf("%lld\n", ans);
	return 0;
}