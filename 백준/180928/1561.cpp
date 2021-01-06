#include <iostream>
using namespace std;

int arr[10001];

int main()
{
	long long N;
	int M;
	scanf("%lld %d", &N, &M);

	for (int i = 1; i <= M; i++)
		scanf("%d", &arr[i]);

	if (N <= M) //������� ���̱ⱸ �� ���� ������ ����������� ź �ⱸ�� ��
	{
		printf("%lld\n", N);
		return 0;
	}

	long long low = 0;
	long long high = 60000000000; //�ִ� �ð�
	long long time = 0;

	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long sum = M; //��ó������ �ⱸ����ŭ ����� Ÿ�Ե�

		for (int i = 1; i <= M; i++)
			sum += (mid / (long long)arr[i]);// mid�ð��� Ÿ���ִ� k���� ���

		if (sum < N) //N���� ������ ��ü �ð��� �ø���.
			low = mid + 1;
		else //�۰ų� ������ ��ü �ð��� ���δ�. ����Ƽ�� ��ġ (����Ž������ �� ������ �ظ� ã�� ���)
		{
			time = mid;
			high = mid - 1;
		}
	}

	long long cnt = M;
	for (int i = 1; i <= M; i++)
		cnt += ((time-1) / arr[i]); //ã�� �ð� 1������ Ÿ���ִ� K���� ����� ã�´�.

	for (int i = 1; i <= M; i++) //time�ð��� Ÿ���ִ� ����� N��° ������� �ⱸ ���� üũ�Ѵ�.
	{
		if (time % arr[i] == 0) cnt++;
		if (cnt == N)
		{
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}