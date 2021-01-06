// 체스 킹나이트 움직이기
#include <iostream>
#include <vector>
using namespace std;

class ChessMetric
{
public:
	long long ways[100][100][55] = { 0 }; //값을 저장하기위한 배열
	int dx[16] = { 1,1,0,-1,-1,-1,0,1,2,1,-1,-2,-2,-1,1,2 }; //킹 나이트가 한번에 움직일수있는 x값
	int dy[16] = { 0,1,1,1,0,-1,-1,-1,1,2,2,1,-1,-2,-2,-1 }; //킹 나이트가 한번에 움직일수있는 y값

	long long howMany(int size, vector<int> start, vector<int> end, int numMoves)
	{
		int sx = start[0], sy = start[1], ex = end[0], ey = end[1];
		ways[sy][sx][0] = 1; //시작지점표시

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
						if (nx < 0 || ny < 0 || nx >= size || ny >= size) // 체스판을 넘어가면 제외
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