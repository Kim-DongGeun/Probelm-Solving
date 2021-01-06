/*
	idea : 높이가 3인 삼각형을 갯수를 늘려가면서 계속 그린다.
*/
#include <iostream>
using namespace std;

int N;
char arr[3073][6145];

void solve(int x, int y, int n)
{
	if (n == 3)
	{
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		for (int i = -2; i < 3; i++)
			arr[y + 2][x + i] = '*';
		return;
	}

 	solve(x, y, n / 2);
	solve(x - n / 2, y + n / 2, n / 2);
	solve(x + n / 2, y + n / 2, n / 2);
}

int main()
{
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2 * N; j++)
			arr[i][j] = ' ';

	solve(N-1, 0, N);

  	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}

	return 0;
}