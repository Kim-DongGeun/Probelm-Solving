//º¸·ù
#include <iostream>
#include <algorithm>
using namespace std;
int map[1001][1001];

int main()
{
	int R, C, a;
	scanf("%d %d", &R, &C);

	for(int i  = 1 ; i< R; i++)
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &map[i][j]);
		}

	if (R % 2 == 0 && C % 2 == 0)
	{
		int Min = 1001;
		pair<int, int> xy;
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				if (Min != min(Min, map[i][j]))
				{
					xy.first = i;
					xy.second = j;
				}

	}
	else
	{
		for (int i = 1; i <= R; i++)
		{
			if (i % 2 == 1) {
				for (int j = 1; j < C; j++)
					printf("R");
			}
			else
			{
				for (int j = 1; j < C; j++)
					printf("L");
			}
			if (i != R)
				printf("D");
		}
	}
	return 0;
}