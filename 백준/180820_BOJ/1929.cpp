#include <iostream>
using namespace std;

int main()
{
	int M, N;
	bool found = false;

	cin >> M >> N;

	
	for(int i = M; i <=N; i++)
	{
		if (i == 1)
			continue;

		for (int j = 2; j <= (int)sqrt(i); j++)
		{
			if (i % j == 0)
			{
				found = true;
				break;
			}
		}

		if (!found)
			printf("%d\n", i);
		else
			found = false;
	}

	return 0;
}