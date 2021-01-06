#include<iostream>
#include<math.h>
using namespace std;

int N, ans;
int col[11];

bool isPromising(int height)
{
	bool change = true;
	int k = 0;
	while (k < height && change) {
		if (col[height] == col[k] || abs(col[height] - col[k]) == height - k)
			change = false;
		k++;
	}
	return change;
}

void queen(int height) {
	if (isPromising(height)) {
		if (height == N - 1) ans++;
		else
		{
			for (int i = 0; i < N; i++) {
				col[height + 1] = i;
				queen(height + 1);
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		ans = 0;

		queen(-1);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}