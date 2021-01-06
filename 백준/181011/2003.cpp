/*
	idea : �ΰ��� �ε��� ������ �ΰ� �� �ε��� ������ ������ ��� ���ؼ� M���� ���Ѵ�
*/
#include <iostream>
using namespace std;

int arr[10001] = { 0 };

int main()
{
	int N, M, a;
	scanf("%d %d", &N, &M);

	int front = 0, rear = 1;

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a);
		arr[i] = a + arr[i - 1];
	}

	int ans = 0;
	while (rear <= N && front <= N)
	{
		if ((arr[rear] - arr[front]) < M) rear++;
		else if ((arr[rear] - arr[front] > M)) front++;
		else if (arr[rear] - arr[front] == M) {
			ans++;
			front++;
		}
	}

	printf("%d\n", ans);
	return 0;
}