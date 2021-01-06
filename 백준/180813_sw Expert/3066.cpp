#include <iostream>
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;

	int* answer = new int[test_case];

	for (int i = 0; i < test_case; i++)
	{
		int M, N, K;

		cin >> N >> M >> K; //남 여 인턴

		for (int j = 0; j < K; j++)
		{
			if (N / 2 < M)
				M--;
			else
				N--;
		}
		if (N / 2 < M)
			answer[i] = N / 2;
		else
			answer[i] = M;
	}

	for (int i = 0; i < test_case; i++)
		cout << "#" << i + 1 << " " << answer[i] << endl;
	return 0;
}