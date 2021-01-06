#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;

		int small = min(A, B);
		int big = max(A, B);

		while (small != 0)
		{
			int temp = small;
			small = big % small;
			big = temp;
		}
		printf("%d\n", A * B / big);
	}
	return 0;
}