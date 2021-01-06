/*
	idea : 수열을 반으로 나누어서 각각 계산하고 합쳤을때 답이 있으면 그것도
			계산한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A[20];
int B[20];

int main()
{
	int N, S;
	scanf("%d %d", &N, &S);

	vector<int> a;
	vector<int> b;

	int left = N / 2;
	int right = N - left;

	for (int i = 0; i < left; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < right; i++)
		scanf("%d", &B[i]);

	for (int i = 0; i < (1 << left); i++)
	{
		int sum = 0;
		for (int j = 0; j < left; j++)
		{
			if(i & (1 << j))
				sum += A[j];
		}
		a.push_back(sum);
	}

	for (int i = 0; i < (1 << right); i++)
	{
		int sum = 0;
		for (int j = 0; j < right; j++)
		{
			if(i & (1 << j))
				sum += B[j];
		}
		b.push_back(sum);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long ans = 0;
	for (int i = 0; i < b.size(); i++)
	{
		auto lo = lower_bound(a.begin(), a.end(), S - b[i]);
		auto hi = upper_bound(a.begin(), a.end(), S - b[i]);
		ans += hi - lo;
	}

	printf("%lld\n", S == 0 ? ans - 1 : ans);
	return 0;
}