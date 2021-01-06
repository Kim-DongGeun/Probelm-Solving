#include <iostream>
using namespace std;

int T, N, K, Max, Min, ans;
int check[10][10] = { 0 };
int arr[10][10];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

struct Data {
	int hight;
	int len;
	int row;
	int col;
	int gongsa;
};

void dfs(Data cur)
{
	ans = ans < cur.len ? cur.len : ans;
	for (int i = 0; i < 4; i++)
	{
		Data next = cur;
		next.row += dy[i];
		next.col += dx[i];
		next.hight = arr[next.row][next.col];

		if (next.row < 0 || next.row >= N || next.col < 0 || next.col >= N) continue;
		if (check[next.row][next.col]) continue;
		
		if (next.hight >= cur.hight) {
			if (next.hight - K < cur.hight && !cur.gongsa)
			{
				check[next.row][next.col] = 1;
				next.len++;
				next.hight = cur.hight - 1;
				next.gongsa = 1;
				dfs(next);
				check[next.row][next.col] = 0;
			}
		}
		else
		{
			check[next.row][next.col] = 1;
			next.len++;
			dfs(next);
			check[next.row][next.col] = 0;
		}
	}
}

int main()
{
	scanf("%d", &T);

	for(int Case = 1; Case <= T; Case++)
	{
		scanf("%d %d", &N, &K);
		ans = 0;
		Max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
				Max = Max > arr[i][j] ? Max : arr[i][j];
			}
		}
		for(int i = 0; i < N ;i++)
			for(int j = 0 ; j < N ;j++)
			{
				if (arr[i][j] == Max) {
					check[i][j] = 1;
					Data d = { arr[i][j] , 1, i, j, 0 };
					dfs(d);
					check[i][j] = 0;
				}
			}

		printf("#%d %d\n", Case, ans);
	}
	return 0;
}

