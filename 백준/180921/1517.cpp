/*
	idea : 머지 소트를 쓰면서 오른쪽부분이 빠질때마다 왼쪽부분의 남은 갯수를
		   모두 더해준다
*/
#include <iostream>
using namespace std;

int arr[500000];
long long ans = 0;

void merge(int low, int high, int mid)
{
	int* U = new int[high - low + 1]();

	int i, j, k;
	i = low;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			U[k++] = arr[i++];
		}
		else
		{
			U[k++] = arr[j++];
			ans += (long long)(mid - i + 1);
		}
	}

	while (j <= high) U[k++] = arr[j++];
	while (i <= mid) U[k++] = arr[i++];

	int index = 0;
	for (int i = low; i <= high; i++)
		arr[i] = U[index++];
	delete[] U;
}

void mergeSort(int low, int high)
{
	if (low >= high) return;
 	int mid = (low + high) / 2;
	mergeSort(low, mid);
	mergeSort(mid + 1, high);
	merge(low, high, mid);
}

int main()
{
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	mergeSort(0, N - 1);

	printf("%lld\n", ans);

	return 0;
}