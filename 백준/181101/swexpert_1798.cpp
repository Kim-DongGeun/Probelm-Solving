/*
	��ΰ� �ʿ�� �ϴ� ������ ���ڿ����ٴ� �迭�� ����ϴ� ���� ������. �ð��ʰ��� �������� �ִ��� �ݺ��� ���� �ǵ��� ����
*/
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define size 36

struct Data {
	char name;
	int score, time;
	Data() {
		name = ' ';
		score = 0;
		time = 0;
	}
};


int check[size];
int path[size];
int ans_path[size];
int map[size][size];
Data node[size];
int ans = 0;
int N, M;


void dfs(int date, int cur, int score, int time, int count, int path[]) {
	if (date > M) return;
	for (int i = 0; i < N; i++)
	{
		if (i == cur) continue; //���� ������ �ڱ� �ڽŰ� ������ ����
		switch (node[i].name) { //���� ������
		case 'P': //�������� ���
			if (check[i]) continue; //�湮������ ����
			if (map[cur][i] + node[i].time + time > 540) continue; //����ð��� ���� �ð� ��� �ð��� ���ļ� 9�ð��� ������ ����
			check[i] = 1; //�湮
			path[count + 1] = i + 1; //��� �߰�
			dfs(date, i, score + node[i].score, map[cur][i] + node[i].time + time, count + 1, path); //�������� �ð��� ������
			check[i] = 0; //�湮����
			path[count + 1] = 0; //��� ����
			break;
		case 'A': //������ ���
			if (date != M || map[cur][i] + time > 540) continue; //���������� �ƴϰų� 9�ð��� ������ ����
			if (ans < score) { //�ִ븸�����̸�
				ans = score; path[count + 1] = i + 1; //�������� ��� ����
				for (int j = 1; j < size; j++) //���� ��θ� ����
					ans_path[j] = path[j];
			}
			break;
		case 'H': //ȣ���� ���
			if (map[cur][i] + time > 540) continue; //9�ð��� ������ ����
			path[count + 1] = i + 1; //��� �߰�
			dfs(date + 1, i, score, 0, count + 1, path); //��¥ + 1
			path[count + 1] = 0; //��� ����
			break;
		}
	}
}

int main()
{
	clock_t b, e;
	b = clock();
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		ans = 0;
		int airport;
		scanf("%d %d", &N, &M);

		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++) {
				scanf("%d", &map[i][j]);
				map[j][i] = map[i][j];
			}

		for (int i = 0; i < N; i++)
		{
			Data d;
			scanf(" %c", &d.name);
			if (d.name == 'P') {
				scanf("%d %d", &d.time, &d.score);
			}
			if (d.name == 'A') airport = i;
			node[i] = d;
		}
		dfs(1, airport, 0, 0, 0, path); //date, cur, score, time, path

		if (!ans) printf("#%d 0\n", t);
		else {
			printf("#%d %d", t, ans);
			for (int i = 0; i < size; i++)
				if (ans_path[i]) printf(" %d", ans_path[i]);
			printf("\n");
		}
	}
	e = clock();
	cout << e - b << "\n";

	return 0;
}

