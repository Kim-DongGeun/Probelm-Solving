/*
	idea : 두개의 인덱스 변수를 두고 두 인덱스 사이의 값들을 모두 더해서 M값과 비교한다
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