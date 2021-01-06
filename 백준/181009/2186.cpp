/*
	idea : 문제에서는 bfs유형이라고 되어있지만 그냥 bfs만으로 풀면 시간초과가 난다. dfs와 메모제이션을 이용해야 시간초과가 안남
			ret 변수에 &를 안붙혀주면 시간초과가 나는 이유를 모르겟음 어려워서 풀이참조함
*/
#include <iostream>
#include <string>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, -1,0,1 };
string word;
char arr[101][101];
int check[101][101][101];
int N, M, K, ans = 0;

int dfs(int y, int x, int n)
{
	if (n == word.length() - 1) return 1;

	int& ret = check[y][x][n]; //참조형태로 선언하지 않으면 시간초과가 난다. 이유는 잘모르겟음

	if (ret != -1) return ret;

	ret = 0;
	for (int i = 1; i <= K; i++)
		for (int j = 0; j < 4; j++)
		{
			int nx = dx[j] * i + x;
			int ny = dy[j] * i + y;
			if (nx < 0 || ny < 0 || nx >= M || ny >= N || arr[ny][nx] != word[n+1]) continue;

			ret += dfs(ny, nx, n + 1);
		}
	return ret;
}

int main()
{
	
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf(" %1c", &arr[i][j]);

	cin >> word;

	for(int i = 0 ;i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < word.length(); k++)
				check[i][j][k] = -1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if(arr[i][j] == word[0])
				ans += dfs(i, j, 0);

	printf("%d\n", ans);
	return 0;
}
/*
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <memory.h>

using namespace std;

#define MAX_NM 100
#define MAX_W 80

int N, M, K;
char input[MAX_NM][MAX_NM + 1];
char w[MAX_W + 1];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cache[MAX_NM][MAX_NM][MAX_W];

int dfs(int y, int x, int n)
{
	if (!w[n + 1])
	{
		return 1;
	}

	int& ret = cache[y][x][n];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int d = 0; d < 4; d++)
	{
		for (int k = 1; k <= K; k++)
		{
			int nx = x + dx[d] * k;
			int ny = y + dy[d] * k;
			if (0 <= nx && nx < M && 0 <= ny && ny < N && w[n + 1] == input[ny][nx])
			{
				ret += dfs(ny, nx, n + 1);
			}
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	//freopen("Text.txt", "r", stdin);
#endif

	memset(cache, -1, sizeof(cache));

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> input[i];
	cin >> w;

	int ans = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (input[y][x] == w[0])
			{
				ans += dfs(y, x, 0);
			}
		}
	}

	cout << ans;

	return 0;
}*/