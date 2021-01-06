#include <iostream>
#include <vector>
using namespace std;

bool visited[2002] = { false };
vector<int> Map[2001];
int N, M, from, to;


void dfs(int depth, int node) {
	if (depth == 4) {
		printf("1\n");
		exit(0);
	}

	for (int i = 0; i < Map[node].size(); i++) {
		if (!visited[Map[node][i]]) {
			visited[Map[node][i]] = true;
			dfs(depth + 1, Map[node][i]);
			visited[Map[node][i]] = false;
		}
	}
}

int main()
{
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &from, &to);
		Map[from].push_back(to);
		Map[to].push_back(from);
	}

	for (int i = 0; i < N; i++) {
		visited[i] = true;
		dfs(0, i);
		visited[i] = false;
	}

	printf("0\n");
	return 0;
}