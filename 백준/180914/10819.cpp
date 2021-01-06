/*
	idea : �迭�� ������ �� ��� ������ ���ؼ� ���� ����Ѵ�.
		   next_permutation �Լ��� ������° ������ ã���ִ� �Լ�
		   ���������� ������ true ������ false
*/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int arr[8];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	int ans = 0;
	do
	{
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
			sum += abs(arr[i] - arr[i + 1]);
		ans = max(ans, sum);
	} while (next_permutation(arr, arr + N)); //���������� ã���ְ� ������ false ����
	
	printf("%d\n", ans);
	return 0;
}