#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class MazeMaker
{
public:
	int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol)
	{
		queue<int> qx;
		queue<int> qy;
		int n = moveRow.size();
		int sx = 0, sy = 0 , ey = maze.size(), ex = maze[0].size();
		int map[50][50];

		for (int i = 0; i < ey; i++)
			for (int j = 0; j < ex; j++)
				map[i][j] = -1;

		//�ʱⰪ
		qx.push(startCol);
		qy.push(startRow);
		map[startRow][startCol] = 0;

		while (!qx.empty())
		{
			int x = qx.front();
			int y = qy.front();
			qx.pop();
			qy.pop();

			for (int i = 0; i < n; i++)
			{
				int dr = y + moveRow[i];
				int dc = x + moveCol[i];

				//�̵��� ��ǥ�� ���ڿ� ������ �����ʰ� Ž������ �ʾҰ� �������������� �߰�
				if (dr >= sy && dr < ey && dc >= sx && dc < ex && maze[dr][dc] == '.' && map[dr][dc] == -1 && maze[dc][dr] == '.')
				{
					qx.push(dc);
					qy.push(dr);
					//�Ÿ�
					map[dr][dc] = map[y][x] + 1;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < ey; i++)
		{
			for (int j = 0; j < ex; j++)
			{
				//���������ִ� ���ε��� Ž������ �ʾ����� -1����
				if (maze[i].substr(j, 1) == "." && map[i][j] == -1)
					return -1;
				ans = max(ans, map[i][j]);
			}
		}
		return ans;
	}
};