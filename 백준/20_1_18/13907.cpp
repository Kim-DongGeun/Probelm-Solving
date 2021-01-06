#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

const int INF = 1000001;

int N, M, K, S, D;
int from, to, cost, t;
int dist[1001][1001];
struct Pos { int to, cost, cnt;
bool operator<(Pos a)const {
	return cost < a.cost;
}
};
vector<vector<Pos>> Map(1001);

void dijkstra(int start, int end) {
	memset(dist, INF, sizeof(dist));

	priority_queue<Pos> q;
	q.push({ start,0, 0 });
	dist[start][0] = 0;

	while (!q.empty()) {
		int cost = -q.top().cost;
		int here = q.top().to;
		int cnt = q.top().cnt;
		q.pop();

		bool find = false;

		for (int i = 0; i <= cnt; i++) { // cost�� ������� ���帹�� ��θ� ������ �ִܰŸ�
										//�׺��� ���� ��ο��� �ִܰŸ��� ������ �н�
			if (dist[here][i] < cost) {
				find = true;
				break;
			}
		}

		if (find) continue;


		for (int i = 0; i < Map[here].size(); i++) {
			int next = Map[here][i].to;
			int nextcost = Map[here][i].cost;


			if (cnt + 1 <= N && dist[next][cnt + 1] > dist[here][cnt] + nextcost) { // ��尳������ ��ΰ����� ������ �н�
				dist[next][cnt + 1] = dist[here][cnt] + nextcost;
				q.push({ next, -dist[next][cnt + 1], cnt + 1 });
			}
		}

		
	}
}

int main() {
	cin >> N >> M >> K;
	cin >> S >> D;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		Map[from].push_back({ to, cost, 0 });
		Map[to].push_back({ from, cost, 0 });
	}
	

	dijkstra(S, D);

	int min = INF;
	int num = -1;
	for (int i = 1; i <= N; i++) { // ó�� �ִܰŸ� ã��
		if (min > dist[D][i]) {
			min = dist[D][i];
			num = i;
		}
	}
	printf("%d\n", min);

	int plus = 0;
	for (int i = 0; i < K; i++) { 
		cin >> t;
		min = INF;
		plus += t;
		for (int j = num; j >= 0; j--) { // ó�� �ִܰŸ��� �����Դ� �Ÿ� �������Ϸ�
										// ������ ������ŭ ����� �λ��ؼ� �ּҰŸ�ã��
			if (min > dist[D][j] + j * plus) {
				min = dist[D][j] + j * plus;
				num = j;
			}
		}
		printf("%d\n", min);
	}


	return 0;
}