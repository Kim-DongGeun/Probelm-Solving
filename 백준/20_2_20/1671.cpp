#include <iostream>
using namespace std;

// bfs로 풀면 시간초과 union find 사용

int parent[100001];
int weight[100001];

int find(int p) {
	if (p == parent[p]) return p;
	int prev = find(parent[p]);
	weight[p] += weight[parent[p]];
	return parent[p] = prev;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	int a, b, w;
	char c;
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		for (int i = 1; i <= N; i++) {
			parent[i] = i;
			weight[i] = 0;
		}

		for (int i = 0; i < M; i++) {
			cin >> c;
			if (c == '!') {
				cin >> a >> b >> w;
				int l = find(a);
				int r = find(b);
				if (l != r) {
					parent[l] = r;
					weight[l] = weight[b] - weight[a] + w;
				}
			}
			else {
				cin >> a >> b;
				int l = find(a);
				int r = find(b);
				if (l != r) cout << "UNKNOWN\n";
				else cout << weight[a] - weight[b] << '\n';
			}
		}
	}
	return 0;
}