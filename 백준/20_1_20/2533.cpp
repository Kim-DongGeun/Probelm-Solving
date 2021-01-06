#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Pos { 
	int to, cost; 
	bool operator==(Pos a) const{
		return to == a.to;
	}
	bool operator<(Pos a) const {
		return to < a.to;
	}
};
struct info { int vertex, cnt, time; string road; };
vector<Pos> Map[501];
vector<string> minPath;

int main() {
	int N, M, S, D, u, v, p;
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		cin >> S >> D;
		for (int i = 0; i < N; i++) {
			Map[i].clear();
		}
		for (int i = 0; i < M; i++) {
			cin >> u >> v >> p;
			Map[u].push_back({ v,p });
		}
		minPath.clear();
		
		bool visited[501] = { false, };
		int Min = 10000000;
		queue<info> q;
		q.push({ S, 0, 0, ""});
		visited[S] = true;

		while (!q.empty()) {
			info cur = q.front();
			q.pop();

			if (cur.vertex == D && Min >= cur.cnt) {
				if (Min > cur.cnt) minPath.clear();
				minPath.push_back(cur.road);
				Min = cur.cnt;
				continue;
			}

			for (int i = 0; i < Map[cur.vertex].size(); i++) {
				if (cur.cnt + Map[cur.vertex][i].cost <= Min && cur.time + 1 <= N) {
					visited[Map[cur.vertex][i].to] = true;
					q.push({ Map[cur.vertex][i].to, cur.cnt + Map[cur.vertex][i].cost, cur.time + 1, cur.road + to_string(cur.vertex) });
				}
			}
		}

		for (int i = 0; i < minPath.size(); i++) {
			minPath[i] += to_string(D);
			for (int j = 1; j < minPath[i].size(); j++) {
				int index = minPath[i][j - 1] - '0';
				int index1 = minPath[i][j] - '0';
				for (auto iter = Map[index].begin(); iter != Map[index].end();) {
					if ((*iter).to == index1) iter = Map[index].erase(iter);
					else iter++;
				}
			}
		}

		vector<int> dist(501);
		fill(dist.begin(), dist.end(), 10000000);
		priority_queue<pair<int, int>>pq;
		pq.push({ 0, S });
		dist[S] = 0;
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			for (int i = 0; i < Map[cur].size(); i++) {
				int nextcost = Map[cur][i].cost;
				int next = Map[cur][i].to;
				if (dist[next] > dist[cur] + nextcost) {
					dist[next] = dist[cur] + nextcost;
					pq.push({ -dist[next], next });
				}
			}
		}
		if (dist[D] == 10000000) printf("-1\n");
		else printf("%d\n", dist[D]);
	}

	return 0;
}