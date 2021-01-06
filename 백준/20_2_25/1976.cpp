#include <iostream>
using namespace std;

int N, M;
int Map[201][201];
int plan[1001];
int parent[201];

int Find(int x) {
	if (x == parent[x])
		return x;
	else {
		int y = Find(parent[x]);
		return parent[x] = y;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	parent[x] = y;
}

int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for(int j = 1 ;j <= N; j++)
			cin >> Map[i][j];

	for (int i = 1; i <= M; i++)
		cin >> plan[i];

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (Map[i][j] == 1) {
				Union(Find(i), Find(j));
			}

	int temp = Find(plan[1]);
	for(int i = 2; i <= M; i++)
		if (Find(plan[i]) != temp) {
			cout << "NO\n"; return 0;
		}

	cout << "YES\n";

	return 0;
}