/*
	idea : ó�����ڸ� ť�� �ְ� -1 -2 -3 �� ���� ť�� ��� �����鼭 
		   3,2,1�� ���� 4,2,1�� ���� ǥ���ǹǷ� ť�� ���� 3,2,1�̸�
		   ����� ���� 4,2,1�� �����ش�.
*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int M;
		scanf("%d", &M);

		queue<int> q;
		q.push(M);

		int sum = 0;
		while (!q.empty())
		{
			int x = q.front();
			
			if (x == 1) sum++;
			else if (x == 2) sum += 2;
			else if (x == 3) sum += 4;
			else
			{
				q.push(x - 1);
				q.push(x - 2);
				q.push(x - 3);
			}
			q.pop();
		}

		printf("%d\n", sum);
	}
	return 0;
}