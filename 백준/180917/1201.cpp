/*
	idea : ������������ �����ѵ� ������ M���� ������ ���̰� K���� �۰� ����� ��� �ϳ��� �κ��� ���̰� K�� �ǵ����ϸ� 
		   �ִ� �κ� ���������� M �ִ� �κ� ���� ������ K�� �ȴ�.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	vector<int> arr(N);
	
	if (M + K - 1 <= N && N <= M * K)
	{
		//�Է�
		for (int i = 0; i < N; i++)
			arr[i] = i + 1;

		vector<int> gap;
		gap.push_back(0); //�ε��� �������� �����ű� ������ ó���� 0�� �־��ش�
		gap.push_back(K);

		N -= K; // ��� �ϳ��� ���̰� K�̾�� �ϹǷ� �̸� K�� ����
		M -= 1;
		int g = M == 0 ? 1 : N / M;
		int r = M == 0 ? 0 : N % M;
		for (int i = 0; i < M; i++)
		{
			gap.push_back(gap.back() + g + (r > 0 ? 1 : 0)); // �������� ���� ������ �� �����ִ� ������ �ε����� ���Ѵ�.
			if (r > 0) r -= 1;
		}

		for (int i = 0; i < gap.size() - 1; i++)
			sort(arr.begin() + gap[i], arr.begin() + gap[i + 1], greater<int>());

		for (int i = 0; i < arr.size(); i++)
			printf("%d ", arr[i]);
	}
	else printf("-1\n");

	return 0;
}