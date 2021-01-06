//������� ����
//������ ����
/*
	idea : �ִ�Ÿ� - �ּҰŸ��� ������ ����� �װ��� �ּҰŸ� ��� �����ϰ� �����⸦ ��ġ�ѵ� �������� ������ ���ų� ������ ������ �ø���
			�������� ������ ������ ������ �ٿ��� ��ġ�ϸ鼭 ������ ���� ã�´�. (�Ķ��Ʈ�� ��ġ �̿� - �����ظ� ã�� �˰���)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[200001];

int main()
{
	int N, C, ans;

	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	int left = 1; //�ּҰŸ�
	int right = arr[N-1] - arr[0]; //�ִ�Ÿ�

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 1;
		int now = arr[0];

		for (int i = 1; i < N; i++)
		{
			if (arr[i] - now >= mid)
			{
				cnt++;
				now = arr[i];
			}
		}

		if (cnt >= C) //������ ������ ������ ������ �ø���.
		{
			ans = mid;
			left = mid + 1;
		}
		else //������ ������ ������ ������ ���δ�.
			right = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}