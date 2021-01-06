/*
	idea : 1 6개와 0 N-6개로 순열을 모두 구하면 N개에서 6개만 뽑은
		   순열의 모두 구할수 있다.
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