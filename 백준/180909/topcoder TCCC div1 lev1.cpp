#include <vector>
using namespace std;

int dx[] = { 1,1,0,-1,-1,-1,0,1,2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 0,1,1,1,0,-1,-1,-1,1,2,2,1,-1,-2,-2,-1 };

long long dp[101][101][51] = { 0 };

class ChessMetric {
public:
	long long howMany(int size, vector<int> start, vector<int> end, int numMoves)
	{
		int startY = start[0];
		int startX = start[1];
		int endY = end[0];
		int endX = end[1];

		//전부 순회하면서 numMoves 값에 따라 갈 수 있는 경로의 갯수를 저장함
		for (int i = 1; i <= numMoves; i++)
		{
			for (int j = 1; j <= size; j++)
			{
				for (int k = 1; k <= size; k++)
				{
					for (int l = 0; l < 16; l++)
					{
						int nextX = startX + dx[l];
						int nextY = startY + dy[l];

						if (nextX > 0 && nextX <= size && nextY > 0 && nextY <= size)
						{
							dp[nextY][nextX][i] += dp[j][k][i - 1];
						}
					}
				}
			}
		}
		return dp[endY][endX][numMoves];
	}
};