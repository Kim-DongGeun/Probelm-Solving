/*
	idea : 1 6���� 0 N-6���� ������ ��� ���ϸ� N������ 6���� ����
		   ������ ��� ���Ҽ� �ִ�.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	while (true)
	{
		scanf("%d", &N);
		if (!N) break;

		vector<int> permutation(N, 1);
		vector<int> arr(N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		for (int i = 6; i < N; i++)
			permutation[i] = 0;

		do
		{
			for (int i = 0 ; i < N; i++)
			{
				if (permutation[i]) printf("%d ", arr[i]);
			}
			printf("\n");
		} while (prev_permutation(permutation.begin(), permutation.end()));
		printf("\n");
	}
	return 0;
}