/*
	idea : ť�� �̿��ϸ�ǰ� �ּ����� ������� ���̳ʽ��� ������
			Ǫ�����ش�.
*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> q;
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int x;
		scanf("%d", &x);

		if (x) q.push(-x);
		else
		{
			printf("%d\n", q.empty() ? 0 : -q.top());
			if (!q.empty()) q.pop();
		}
	}
	return 0;
}