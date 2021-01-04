#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };


using namespace std;
int visited[1000001];
int F, S, G, U, D;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> F >> S >> G >> U >> D;

	fill(visited, visited + 1000001, INT32_MAX);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, S });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (visited[cur] <= cost) continue;
		visited[cur] = cost;

		if (cur == G) {
			cout << cost;
			return 0;
		}

		if (cur + U <= F) pq.push({ cost + 1, cur + U });
		if (cur - D >= 1) pq.push({ cost + 1, cur - D });
	}
	cout << "use the stairs";
	

	return 0;
}