#include<iostream>
#include<map>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	while (N--)
	{
		map<int, int> m;
		int T, a;
		scanf("%d", &T);

		for (int i = 0; i < 1000; i++) {
			scanf("%d", &a);
			m[a]++;
		}
		pair<int, int> max = { 0,0 };
		for (int i = 0; i <= 100; i++)
		{
			if (max.first <= m[i]) {
				max.first = m[i];
				max.second = i;
			}
		}
		printf("#%d %d\n", T, max.second);
	}
	return 0;
}