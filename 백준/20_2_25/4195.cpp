#pragma warning (disable : 4996)
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<int> parent;
vector<pair<string, string>> arr;
map<string, int> m;
int c[200001];

int Find(int x) {
	if (x == parent[x]) return x;
	else {
		int y = Find(parent[x]);
		return parent[x] = y;
	}
}

int Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[x] = y;
		c[y] += c[x]; // 친구 관계 기록
	}

	return c[y];
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		m.clear();
		int F;
		scanf("%d", &F);
		
		arr.resize(F + 1);
		int index = 1;
		for (int i = 0; i < F; i++) {
			char a[21], b[21];
			scanf("%s %s", &a, &b);
			arr[i].first = a;
			arr[i].second = b;
			if (m.count(a) == 0)
				m[a] = index++;
			if (m.count(b) == 0)
				m[b] = index++;
		}

		parent.resize(m.size() + 1);
		for (int i = 1; i <= m.size(); i++) {
			parent[i] = i; c[i] = 1;
		}

		for (int i = 0; i < F; i++) {
			printf("%d\n", Union(m[arr[i].first], m[arr[i].second]));
			/*int temp = m[arr[i].second]; // 시간초과
			int cnt = 0;
			for (int j = 1; j <= m.size(); j++)
				if (Find(temp) == Find(parent[j])) cnt++;*/
		}
		
	}
	return 0;
}