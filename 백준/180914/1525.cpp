/*
	º¸·ù
*/

#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
map<int, int> dist;

int main()
{
	int start = 0, a;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			scanf("%d", &a);
			if (a == 0)
				a = 9;
			start = 10 * start + a;
		}

	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		string curString = to_string(cur);


	}


	
}