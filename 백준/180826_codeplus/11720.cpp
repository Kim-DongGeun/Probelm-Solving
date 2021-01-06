/*
	입력받는 길이를 제한할수있다.
*/
#include <iostream>
using namespace std;

int main()
{
	int N, sum = 0, d;
	scanf("%d", &N);

	while (N--)
	{
		scanf("%1d", &d);
		sum += d;
	}
	printf("%d\n", sum);
	return 0;
}