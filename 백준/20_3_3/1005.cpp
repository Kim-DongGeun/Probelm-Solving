#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;


int time[1001];
int dp[1001];
int N, D, END, u, v;
//vector<int> Map[1001];
//vector<int> parent(1001);
int Map[1001][1001];


int dfs(int destination) { // 도착점을 기준으로 dfs + dp
	
	int& ret = dp[destination];
	if (ret != -1) return ret;


	int duration = 0;
	for (int i = 1; i <= N; i++) {
		if (Map[i][destination]) {
			duration = max(duration, dfs(i));
		}
	}
	return ret = time[destination] + duration;
}

//int dfs(int cur) { 시작지점부터 시작하면 시간초과 왜 안될까
//	if (cur == END) return time[cur];
//
//	int& ret = dp[cur];
//	if (ret != -1) return ret;
//
//	ret = -1;
//	for (int i = 0; i < Map[cur].size(); i++) {
//		int temp = dfs(Map[cur][i]);
//		if(temp >= 0)
//			ret = max(ret, temp + time[cur]);
//	}
//
//	return ret;
//}
//
//int Find(int cur) {
//	if (cur == parent[cur]) return cur;
//	else return parent[cur] = Find(parent[cur]);
//}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {

		memset(Map, 0, sizeof(Map));
		memset(dp, -1, sizeof(dp));

		cin >> N >> D;
		//for (int i = 1; i <= N; i++) Map[i].clear();
		//for (int i = 1; i <= N; i++) parent[i] = i;
		for (int i = 1; i <= N; i++) cin >> time[i];
		for (int j = 0; j < D; j++) {
			cin >> u >> v;
			Map[u][v] = 1;
			/*Map[u].push_back(v);
			parent[v] = u;*/
		}
		cin >> END;

		cout << dfs(END) << '\n';

		/*set<int> s; 
		for (int i = 1; i <= N; i++) s.insert(Find(i));
		

		fill(dp, dp + N + 1, -1);
		int ans = 0;
		for (auto iter = s.begin(); iter != s.end(); iter++) {
			ans = max(ans, dfs(*iter));
		}
			
		cout << ans << '\n';*/


		/*vector<int> dist(20001);
		fill(dist.begin(), dist.end(), -1); // 다익스트라로 풀어도 시간초과
		priority_queue<pair<int, int>> q;
		q.push({ time[1], 1 });
		dist[1] = time[1];
		while (!q.empty()) {
			int cur = q.top().second;
			int cost = q.top().first;
			q.pop();

			if (cur == END) break;

			for (int i = 0; i < Map[cur].size(); i++) {
				int next = Map[cur][i];
				int nextcost = time[next];
				if (dist[next] < dist[cur] + nextcost) {
					dist[next] = dist[cur] + nextcost;
					q.push({ dist[next], next });
				}
			}
		}

		cout << dist[END] << '\n';*/


		//int visited[1001] = { 0, };  bfs로 풀면 시간초과
		/*queue<pair<int, int>> q;
		q.push({ 1, time[1] });
		visited[1] = time[1];
		while (!q.empty()) {
			int cur = q.front().first;
			int cost = q.front().second;

			q.pop();

			if (cur == END) {
				ans = max(ans, cost);
				continue;
			}

			for (int i = 0; i < Map[cur].size(); i++) {
				if (visited[Map[cur][i]] < cost + time[Map[cur][i]] && Map[Map[cur][i]].size() >= 1) {
					visited[Map[cur][i]] = cost + time[Map[cur][i]];
					q.push({ Map[cur][i], cost + time[Map[cur][i]] });
				}
			}
		}*/

		//cout << ans << '\n';
	}
	return 0;
}
