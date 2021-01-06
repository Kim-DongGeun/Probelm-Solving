/*
	idea : 10000까지 소수를 먼저 찾고 시작 현재 숫자에서 각자리를 하나씩 바꿔서
		   소수인지 판별하고 방문하지 않았으면 큐에 넣는 방법으로 함
		   최단 거리는 bfs
*/
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

bool arr[10000];
int check[10000] = { 0 };

int changeNum(int num, int index, int digit) //해당 인덱스의 숫자를 바꿈
{
	if (index == 0 && digit == 0)
		return -1;

	string temp = to_string(num);
	temp[index] = digit + '0';

	return stoi(temp);
}

int main()
{
	for (int i = 2; i <= 9999; i++)
		arr[i] = true;

	for (int i = 2;i <= 9999; i++) //에라토스테네스의 체 소수판별
	{
		if (arr[i] == 0)continue;
		for (int j = i + i; j <= 9999; j += i) arr[j] = false;
	}

	int T;
	scanf("%d", &T);

	while (T--)
	{
		int A, B;
		scanf("%d %d", &A, &B);

		for (int i = 1; i < 10000; i++)
			check[i] = 0;
		
		queue<int> q;
		q.push(A);
		check[A] = 1; //체크의 의미로 1로 표시함

		bool out = false;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			if (x == B) { //타겟에 도달하면 탈출
				out = true;
				break;
			}

			for (int i = 0; i < 4; i++) //4개의 자리 각각
			{
				for (int j = 0; j < 10; j++) // 0~9 숫자
				{
					int next = changeNum(x, i, j); //한자리 바꾼 숫자

					if (next != -1 && arr[next] == true && !check[next])//방문안하고 소수이면
					{
						check[next] = check[x] + 1;//거리 저장
						q.push(next);//큐에 넣음
					}
				}
			}
		}
		if (out) printf("%d\n", check[B] - 1); //찾으면 맨처음 1넣은걸 뻄
		else printf("Impossible\n"); //못찾으면
	}
	return 0;
}