/*
	idea : 오른차순으로 정렬한뒤 수열을 M개로 나누고 길이가 K보다 작게 만들고 적어도 하나의 부분의 길이가 K가 되도록하면 
		   최대 부분 증가수열이 M 최대 부분 감소 수열이 K가 된다.
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
		//입력
		for (int i = 0; i < N; i++)
			arr[i] = i + 1;

		vector<int> gap;
		gap.push_back(0); //인덱스 기준으로 나눌거기 때문에 처음에 0을 넣어준다
		gap.push_back(K);

		N -= K; // 적어도 하나는 길이가 K이어야 하므로 미리 K는 뺴줌
		M -= 1;
		int g = M == 0 ? 1 : N / M;
		int r = M == 0 ? 0 : N % M;
		for (int i = 0; i < M; i++)
		{
			gap.push_back(gap.back() + g + (r > 0 ? 1 : 0)); // 나머지가 남아 있으면 몫에 더해주는 식으로 인덱스를 정한다.
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