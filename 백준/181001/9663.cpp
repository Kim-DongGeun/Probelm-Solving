#include <iostream>
using namespace std;

bool check[15][15];
int N, ans = 0;

bool Check(int row, int col)
{
	//윗줄 검사
	for (int i = 0; i < N; i++)
	{
		if (i == row) continue;
		if (check[i][col]) return false;
	}
	
	//왼쪽대각선 검사
	int x = col - 1;
	int y = row - 1;

	while (x >= 0 && y >= 0)
	{
		if (check[y][x]) return false;
		x--;
		y--;
	}

	//오른쪽대각선 검사
	x = col + 1;
	y = row - 1;

	while (x < N && y >= 0)
	{
		if (check[y][x]) return false;
		x++;
		y--;
	}
	return true;
}

void cal(int row)
{
	if (row == N) ans++;
	for (int col = 0; col < N; col++)
	{
		check[row][col] = true;
		if (Check(row, col)) cal(row + 1);
		check[row][col] = false;
	}
}

int main()
{
	scanf("%d", &N);

	cal(0);

	printf("%d\n", ans);
	return 0;
}