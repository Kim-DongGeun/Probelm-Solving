#include <iostream>
#include <math.h>
using namespace std;

#define MAX 4000001
#define MAX_NUM 283146
int arr[MAX] = { 0 };
int temp[MAX_NUM];

void cal()
{
	for (int i = 2; i < MAX; i++)
		arr[i] = i;

	int n = sqrt(MAX);
	for (int i = 2; i < n; i++)
	{
		if (!arr[i]) continue;
		for (int j = i + i; j < MAX; j += i)
		{
			arr[j] = 0;
		}
	}

	for (int i = 2, j = 0; i < MAX; i++)
		if (arr[i]) temp[j++] = arr[i];
}

int main()
{
	int N; // ~4,000,000
	scanf("%d", &N);

	int r = 0, l = 0, ans = 0;

	cal(); //소수구하기

	int sum = 0;
	while (l <= r && r < MAX_NUM && temp[l] <= N) {
		if (sum < N) {
			sum += temp[r];
			r++;
		}
		else
		{
			if (sum == N) ans++;
			sum -= temp[l];
			l++;
		}
	}
	printf("%d\n", ans);
	return 0;
}