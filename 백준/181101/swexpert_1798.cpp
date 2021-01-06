/*
	경로가 필요로 하는 문제는 문자열보다는 배열을 사용하는 것이 빠르다. 시간초과가 날때에는 최대한 반복이 적게 되도록 하자
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
		if (i == cur) continue; //다음 순서가 자기 자신과 같으면 무시
		switch (node[i].name) { //다음 노드기준
		case 'P': //관광지일 경우
			if (check[i]) continue; //방문했으면 무시
			if (map[cur][i] + node[i].time + time > 540) continue; //현재시간과 가는 시간 노는 시간을 합쳐서 9시간이 넘으면 무시
			check[i] = 1; //방문
			path[count + 1] = i + 1; //경로 추가
			dfs(date, i, score + node[i].score, map[cur][i] + node[i].time + time, count + 1, path); //만족도와 시간을 더해줌
			check[i] = 0; //방문해제
			path[count + 1] = 0; //경로 삭제
			break;
		case 'A': //공항일 경우
			if (date != M || map[cur][i] + time > 540) continue; //마지막날이 아니거나 9시간이 넘으면 무시
			if (ans < score) { //최대만족도이면
				ans = score; path[count + 1] = i + 1; //만족도와 경로 저장
				for (int j = 1; j < size; j++) //최적 경로를 저장
					ans_path[j] = path[j];
			}
			break;
		case 'H': //호텔일 경우
			if (map[cur][i] + time > 540) continue; //9시간이 넘으면 무시
			path[count + 1] = i + 1; //경로 추가
			dfs(date + 1, i, score, 0, count + 1, path); //날짜 + 1
			path[count + 1] = 0; //경로 삭제
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

