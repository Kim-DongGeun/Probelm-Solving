#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> K >> M;

	vector<vector<int>> arr(N + M + 1);
	vector<int> visited(N + M + 1, 0);

	int x;
	for (int i = N + 1; i < N + M + 1; i++) {
		for (int j = 0; j < K; j++) {
			cin >> x;
			arr[x].push_back(i);
			arr[i].push_back(x);
		}
	}

	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == N) {
			cout << visited[cur] / 2 + 1 << '\n';
			return 0;
		}

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i];
			if (!visited[next]) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}

	cout << "-1\n";

	return 0;
}