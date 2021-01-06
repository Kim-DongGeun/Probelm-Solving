/*
	idea : 처음숫자를 큐에 넣고 -1 -2 -3 한 값을 큐에 계속 넣으면서 
		   3,2,1는 각각 4,2,1의 경우로 표현되므로 큐의 값이 3,2,1이면
		   경우의 수에 4,2,1을 더해준다.
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