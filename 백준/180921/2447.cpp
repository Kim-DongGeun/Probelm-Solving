/*
	idea : 9k개 중에 가운데가 뚫여있는 규칙이 반복됨
		   크기를 줄여가면서 재귀적으로 수행해준다
*/
#include <iostream>
using namespace std;

char arr[2187][2187];

void solve(int x, int y, int n)
{
	if (n <= 1)return;

	for (int i = y + n / 3; i < y + 2 * n / 3; i++)
		for (int j = x + n / 3; j < x + 2 * n / 3; j++)
			arr[i][j] = ' ';

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			solve(x + j * n / 3, y + i * n / 3, n / 3);
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = '*';

	solve(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}

	return 0;
}