#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	long long A, B;
	cin >> A >> B;

	long long small = min(A, B);
	long long big = max(A, B);

	while (small != 0)
	{
		long long temp = small;
		small = big % small;
		big = temp;
	}

	for (int i = 0; i < big; i++)
		printf("1");
	printf("\n");
	return 0;
}