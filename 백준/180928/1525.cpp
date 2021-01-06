/*
	idea : 0을 9로 놓고 9자리 정수로 바꾸어서 map에 넣고 9의 위치를
		   바꾸면서 마지막 123456789가 map에 없으면 -1 있으면 그 값을 
		   출력을 해준다.
*/
#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	int start = 0, a;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &a);
			if (a == 0) {
				a = 9;
			}
			start = 10 * start + a; //9자리 숫자로 저장해줌
		}
	map<int, int> d;
	d[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int now = q.front();
		string now_str = to_string(now);
		q.pop();

		int z = now_str.find('9'); //9의 x y 좌표를 찾음
		int x = z % 3;
		int y = z / 3;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
			string next = now_str;
			swap(next[3 * y + x], next[3 * ny + nx]); //다음좌표와 위치를 바꾼다.
			int num = stoi(next);
			if (d.count(num) == 0) { //맵에 없으면
				d[num] = d[now] + 1;
				q.push(num);
			}
		}
	}
	if (d.count(123456789) == 0) printf("-1\n");
	else printf("%d\n", d[123456789]);
	return 0;
}