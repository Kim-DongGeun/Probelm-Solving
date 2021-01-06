#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

struct Pos {
	int from, to, time;
	bool operator<(Pos a) const {
		return time < a.time;
	}
};

#define INF 1000000000

vector<Pos> Map;

int main() {
	int N, M, u, v, t;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> t;
		Map.push_back({ u,v,t });
	}


	int dist[501];
	for (int i = 1; i <= N; i++) dist[i] = INF;

    dist[1] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int u = Map[j].from;
            int v = Map[j].to;
            int weight = Map[j].time;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int j = 0; j < M; j++)
    {
        int u = Map[j].from;
        int v = Map[j].to;
        int weight = Map[j].time;
		if (dist[u] != INF && dist[u] + weight < dist[v]) {
			printf("-1\n");
			return 0;
		}
    }


	for (int i = 2; i <= N; i++) {
		if (dist[i] == INF) printf("-1\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}