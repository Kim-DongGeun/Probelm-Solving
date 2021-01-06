/*
	idea : 비트마스크 사용
*/
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int M, x;
	char input[7];
	int arr = 0;

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%s", input);
		if (!strcmp(input, "add"))
		{
			scanf("%d", &x);
			arr = arr | (1 << x); //추가
		}
		else if (!strcmp(input, "remove"))
		{
			scanf("%d", &x);
			arr = arr & ~(1 << x); //제거
		}
		else if (!strcmp(input, "check"))
		{
			scanf("%d", &x);
			if (arr & (1 << x)) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(input, "toggle"))
		{
			scanf("%d", &x);
			arr = arr ^ (1 << x);
		}
		else if (!strcmp(input, "all"))
		{
			arr = arr | (1 << 21) - 1;
		}
		else if (!strcmp(input, "empty"))
		{
			arr = 0;
		}
	}
	return 0;
}