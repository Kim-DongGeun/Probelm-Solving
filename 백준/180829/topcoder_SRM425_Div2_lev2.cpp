
class CrazyBot
{
	bool map[30][30] = { false };
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	double dir[4];

public:
	double getProbability(int n, int east, int west, int south, int north)
	{
		double ans = 0;
		
		dir[0] = east / 100.0;
		dir[1] = west / 100.0;
		dir[2] = south / 100.0;
		dir[3] = north / 100.0;

		return dfs(15, 15, n);
	}

	double  dfs(int x, int y, int n)
	{
		//종료 조건
		if (map[y][x] == true) return 0;
		if (n == 0) return 1;

		//로봇이 지나갔다는걸 표시
		map[y][x] = true;

		double ret = 0;
		for (int i = 0; i < 4; i++)
		{
			ret += dir[i] * dfs(y + dy[i], x + dx[i], n - 1);
		}
		//탐색을 마치고 돌아가면서 표시해뒀던걸 지움
		map[y][x] = false;
		return ret;
	}
};
