#include <iostream>
using namespace std;

int map[100][100];

int main()
{
	for (int t = 1; t <= 10; t++) {
		int N;
		scanf("%d", &N);

		int max = 0;

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				scanf("%d", &map[i][j]);

		int sum = 0;
		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++)
				sum += map[i][j];
			max = max < sum ? sum : max;
		}

		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++)
				sum += map[j][i];
			max = max < sum ? sum : max;
		}

		sum = 0;
		for (int i = 0; i < 100; i++)
			sum += map[i][i];
		max = max < sum ? sum : max;

		sum = 0;
		for (int i = 0; i < 100; i++)
			sum += map[99 - i][i];
		max = max < sum ? sum : max;
		printf("#%d %d\n", t, max);
	}
	return 0;
}