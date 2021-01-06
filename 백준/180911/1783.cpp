#include <iostream>
#include <algorithm>
using namespace std; 

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);	

	if (N == 1)printf("1\n");
	else if (N == 2) printf("%d\n", min(4, (M + 1) / 2));
	else
	{
		if (M < 7)printf("%d\n", min(4, M));
		else printf("%d\n", M - 2);
	}
	return 0;
}