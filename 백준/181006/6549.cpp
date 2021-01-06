/*
	idea : ������ �̿��Ͽ� ���� ���簢�� ���� ���̰� ���� ���� �簢���� �ε����� ã��
			���̰� ���� ������ �簢���߿��� ���� ������ �簢���� �ε����� ã�Ƽ�
			���̸� ������ �ִ��� ã�´�.
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	long long arr[100000] = { 0 };
	long long n, h, ans;
	
	while (scanf("%d", &n) == 1 && n != 0) {
		for (int i = 0; i < n; i++)
			scanf("%lld", &arr[i]);
		stack<long long> s;
		ans = 0;

		for (int i = 0; i < n; i++)
		{
			while (!s.empty() && arr[s.top()] > arr[i]) //���� ���̰� �� ������
			{
				long long hight = arr[s.top()];
				s.pop();
				long long width = i;
				if (!s.empty()) width = i - 1 - s.top();
				if (ans < hight * width) ans = hight * width;
			}
			s.push(i);
		}
		while (!s.empty())
		{
			long long hight = arr[s.top()];
			s.pop();
			long long width = n;
			if (!s.empty()) width = n - 1 - s.top();
			if (ans < hight * width) ans = hight * width;
		}
		printf("%lld\n", ans);
	}
	return 0;
}