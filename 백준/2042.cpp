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

int n, m, k;

long long init(vector<long long>& v, vector<long long>& tree, int node, int start, int end) {
	if (start == end) return tree[node] = v[start]; // 배열값 넣기
	else return tree[node] = init(v, tree, node * 2, start, (start + end) / 2) + init(v, tree, node * 2 + 1, (start + end) / 2 + 1, end); // 구간합 구하기
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] += diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	else if (left <= start && right >= end) return tree[node];
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	cin >> n >> m >> k;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);
	init(v, tree, 1, 0, n - 1);
	m += k;
	while (m--) {
		long long a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			b--;
			long long diff = c - v[b];
			v[b] = c;
			update(tree, 1, 0, n - 1, b, diff);
		}
		else {
			cin >> b >> c;
			cout << sum(tree, 1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}
	return 0;
}

