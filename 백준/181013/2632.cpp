/*
	idea : 피자 조각의 부분수열을 모두 구해야함 원으로 되어있기 때문에 시작인덱스 이전까지 포함하는 조각도 생각해야됨
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T, m, n;
	scanf("%d", &T);
	scanf("%d %d", &m, &n);
	vector<int> A(m);
	vector<int> B(n);
	int sumA = 0, sumB = 0;

	for (int i = 0; i < m; i++) {
		scanf("%d", &A[i]);
		sumA += A[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
		sumB += B[i];
	}

	vector<int> a;
	vector<int> b;

	for (int front = 0; front < m; front++)
	{
		for (int rear = 0; rear < m; rear++)
		{
			if (rear >= front) {
				int sum = 0;
				for (int i = front; i <= rear; i++) {
					sum += A[i];
				}
				a.push_back(sum);
			}
			else {
				if (front - 1 == rear) continue;
				int sum = 0;
				for (int i = front; i < m; i++) {
					sum += A[i];
				}
				for (int i = 0; i <= rear; i++) {
					sum += A[i];
				}
				a.push_back(sum);
			}
		}
	}
	

	for (int front = 0; front < n; front++)
	{
		for (int rear = 0; rear < n; rear++)
		{
			if (rear >= front) {
				int sum = 0;
				for (int i = front; i <= rear; i++) {
					sum += B[i];
				}
				b.push_back(sum);
			}
			else {
				if (front - 1 == rear) continue;
				int sum = 0;
				for (int i = front; i < n; i++) {
					sum += B[i];
				}
				for (int i = 0; i <= rear; i++) {
					sum += B[i];
				}
				b.push_back(sum);
			}
		}
	}

	long long ans = 0;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	auto lo = lower_bound(a.begin(), a.end(), T);
	auto hi = upper_bound(a.begin(), a.end(), T);
	ans += hi - lo;

	lo = lower_bound(b.begin(), b.end(), T);
	hi = upper_bound(b.begin(), b.end(), T);
	ans += hi - lo;

	for (int i = 0; i < a.size(); i++)
	{
		int target = T - a[i];
		lo = lower_bound(b.begin(), b.end(), target);
		hi = upper_bound(b.begin(), b.end(), target);
		ans += hi - lo;
	}

	printf("%lld\n", ans);
	return 0;
}