/*
	idea : 들어오는 사람이 볼수있는 사람의 수를 더해가면서 답을 찾는다.
			내방식으로는 안풀려서 풀이참조함
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