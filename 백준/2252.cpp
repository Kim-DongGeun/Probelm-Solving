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

vector<int> arr(32001, 0);
vector<int> edge[32001];


int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		arr[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (arr[i] == 0) q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << ' ';
		for (int i = 0; i < edge[cur].size(); i++) {
			arr[edge[cur][i]]--;
			if (arr[edge[cur][i]] == 0) q.push(edge[cur][i]);
		}
	}


	return 0;
}

