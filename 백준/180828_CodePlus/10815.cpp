#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N, M;

	scanf("%d", &N);

	set<int> arr;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &M);
		arr.insert(M);
	}

	scanf("%d", &M);

	//�˰��� ���̳ʸ���ġ�� ����ϴϱ� �ð��ʰ���
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &N);
		printf("%d ", arr.count(N));
	}
	return 0;
}