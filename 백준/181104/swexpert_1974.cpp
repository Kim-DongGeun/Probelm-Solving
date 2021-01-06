#include <iostream>
using namespace std;

#define SUM 45
int map[9][9];

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int ans = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				scanf("%d", &map[i][j]);

		int sum;
		for (int i = 0; i < 9; i++) {
			sum = 0;
			for (int j = 0; j < 9; j++)
				sum += map[i][j];
			if (sum == SUM) ans++;
		}

		sum = 0;
		for (int i = 0; i < 9; i++) {
			sum = 0;
			for (int j = 0; j < 9; j++)
				sum += map[j][i];
			if (sum == SUM) ans++;
		}

		sum = 0;
		for (int i = 0; i < 9; i += 3)
			for (int j = 0; j < 9; j += 3) {
				sum = 0;
				for (int k = 0; k < 3; k++)
					for (int l = 0; l < 3; l++)
						sum += map[i + k][j + l];
				if (sum == SUM) ans++;
			}
		printf("#%d %d\n", t, ans == 27 ? 1 : 0);
	}
	return 0;
}