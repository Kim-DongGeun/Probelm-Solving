/*
	처음에 while안에 조건을 넣었는데 시간초과남
	조건을 밖으로 뺴니깐 통과
*/
#include <iostream>
using namespace std;

int main()
{
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	int ans = 1;

	while (true)
	{
		if ((ans - E) % 15 == 0 && (ans - S) % 28 == 0 && (ans - M) % 19 == 0)
			break;
		ans++;
	}
		
	printf("%d\n", ans);
	return 0;
}