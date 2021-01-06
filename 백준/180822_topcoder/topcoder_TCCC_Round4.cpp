// ü�� ŷ����Ʈ �����̱�
#include <iostream>
#include <vector>
using namespace std;

class ChessMetric
{
public:
	long long ways[100][100][55] = { 0 }; //���� �����ϱ����� �迭
	int dx[16] = { 1,1,0,-1,-1,-1,0,1,2,1,-1,-2,-2,-1,1,2 }; //ŷ ����Ʈ�� �ѹ��� �����ϼ��ִ� x��
	int dy[16] = { 0,1,1,1,0,-1,-1,-1,1,2,2,1,-1,-2,-2,-1 }; //ŷ ����Ʈ�� �ѹ��� �����ϼ��ִ� y��

	long long howMany(int size, vector<int> start, vector<int> end, int numMoves)
	{
		int sx = start[0], sy = start[1], ex = end[0], ey = end[1];
		ways[sy][sx][0] = 1; //��������ǥ��

		for (int i = 1; i <= numMoves; i++)
		{
			for (int x = 0; x < size; x++)
			{
				for (int y = 0; y < size; y++)
				{
					for (int j = 0; j < 16; j++)
					{
						int nx = x + dx[j];
						int ny = y + dy[j];
						if (nx < 0 || ny < 0 || nx >= size || ny >= size) // ü������ �Ѿ�� ����
							continue;

						ways[ny][nx][i] += ways[y][x][i - 1];
					}
				}
			}
		}
		return ways[ey][ex][numMoves];
	}
};


int main()
{
	return 0;
}