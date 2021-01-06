#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> relation[501];
set<int> s;

int main() {
	int N, M, from, to;
	cin >> N >> M;



	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		relation[from].push_back(to);
		relation[to].push_back(from);
	}

	int ans = 0;
	for (int i = 0; i < relation[1].size(); i++) {
		int next = relation[1][i];
		s.insert(next);
		for (int j = 0; j < relation[next].size(); j++)
			s.insert(relation[next][j]);
	}
	cout << s.size() - 1 << '\n';
	return 0;
}