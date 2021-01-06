/*
		idea : bfs로 최소 횟수를 구한다.
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

long long check[10000];
string ans = "";

int changeString(int index, int input)
{
	int a;
	switch (index)
	{
	case 0: //D
		input = (2 * input) % 10000;
		break;
	case 1: //S
		if (input == 0) input = 9999;
		else input -= 1;
		break;
	case 2: //L
		a = input / 1000;
		input = (input % 1000) * 10 + a;
		break;
	case 3: //R
		a = input % 10;
		input = (input / 10) + a * 1000;
		break;
	}
	return input;
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int from, to;
		cin >> from >> to;

		for (int i = 0; i < 10000; i++)
			check[i] = 0;

		queue<int> q;
		q.push(from);
		check[from] = 4;

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			if (cur == to)
				break;

			for (int i = 0; i < 4; i++)
			{
				int next = changeString(i, cur);

				if (check[next] == 0) //방문안했으면
				{
					q.push(next);
					check[next] = (long long)(10 * check[cur] + i); //순서대로 배열함
				}
			}
		}

		for (char x : to_string(check[to]))
		{
			if (x == '0') printf("D");
			else if (x == '1') printf("S");
			else if (x == '2') printf("L");
			else if (x == '3') printf("R");
		}
		printf("\n");

	}
	return 0;
}