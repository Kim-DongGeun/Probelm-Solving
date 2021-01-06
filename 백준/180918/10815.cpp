/*
	idea : �� ������ ó������ ���ʴ�� ���� ���� ���ο� �迭�� �߰��Ѵ�
*/
#include <iostream>
#include <vector>
using namespace std;

int arr1[1000001];
int arr2[1000001];
vector<int> ans;

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr1[i]);
	for (int i = 1; i <= M; i++)
		scanf("%d", &arr2[i]);

	int index1 = 1, index2 = 1;

	while (index1 <= N && index2 <= M)
	{
		if (arr1[index1] < arr2[index2])
		{
			ans.push_back(arr1[index1]);
			index1++;
		}
		else
		{
			ans.push_back(arr2[index2]);
			index2++;
		}

		if (index1 == N + 1)
			while (index2 <= M) ans.push_back(arr2[index2++]);
		else if (index2 == M + 1)
			while (index1 <= N) ans.push_back(arr1[index1++]);
	}

	for (int x : ans)
		printf("%d ", x);
	return 0;
}