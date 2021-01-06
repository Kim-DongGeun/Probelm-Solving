/*
	idea : 0�� 9�� ���� 9�ڸ� ������ �ٲپ map�� �ְ� 9�� ��ġ��
		   �ٲٸ鼭 ������ 123456789�� map�� ������ -1 ������ �� ���� 
		   ����� ���ش�.
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
			start = 10 * start + a; //9�ڸ� ���ڷ� ��������
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

		int z = now_str.find('9'); //9�� x y ��ǥ�� ã��
		int x = z % 3;
		int y = z / 3;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
			string next = now_str;
			swap(next[3 * y + x], next[3 * ny + nx]); //������ǥ�� ��ġ�� �ٲ۴�.
			int num = stoi(next);
			if (d.count(num) == 0) { //�ʿ� ������
				d[num] = d[now] + 1;
				q.push(num);
			}
		}
	}
	if (d.count(123456789) == 0) printf("-1\n");
	else printf("%d\n", d[123456789]);
	return 0;
}