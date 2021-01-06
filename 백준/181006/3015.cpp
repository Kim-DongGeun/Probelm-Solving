/*
	idea : ������ ����� �����ִ� ����� ���� ���ذ��鼭 ���� ã�´�.
			��������δ� ��Ǯ���� Ǯ��������
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int arr[500000];
	int N;
	long long ans = 0;
	scanf("%d", &N);

	stack<int> s;
	stack<int> c;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++)
	{
		int h = arr[i];
		int cnt = 1;

		while (!s.empty())
		{
			if (s.top() <= arr[i])
			{
				ans += (long long)c.top();
				if (s.top() == arr[i])
				{
					cnt += c.top();
				}
				s.pop();
				c.pop();
			}
			else break;
		}
		if (!s.empty()) ans++;

		s.push(h);
		c.push(cnt);
	}
	printf("%lld\n", ans);
	return 0;
}