#include <iostream>
using namespace std;

int main()
{
	int arr[1000];
	int T;
	for (int t = 1; t <= 10; t++)
	{
		scanf("%d", &T);
		for (int i = 0; i < T; i++)
			scanf("%d", &arr[i]);
		int ans = 0;
		for (int i = 2; i < T - 2; i++)
		{
			int max = 0;
			bool found = false;
			for (int j = 0; j < 5; j++)
			{
				if (j == 2) continue;
				if (max < arr[i + j - 2]) max = arr[i + j - 2];
				if (arr[i + j - 2] > arr[i]) {
					found = true;
					break;
				}
			}
			if (!found) ans += arr[i] - max;
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}