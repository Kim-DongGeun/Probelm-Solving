#include <iostream>
#include <algorithm>
using namespace std;

int main()
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

	printf("%d\n", big);
	printf("%d\n", A * B / big);

	return 0;
}