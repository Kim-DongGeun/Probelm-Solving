/*
	set�� ����ϸ� �ð��ʰ��� ���� map���
*/
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N, a;
	map<int, int> arr;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		arr[a]++;
	}

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		printf("%d ", arr[a]);
	}
	return 0;
}