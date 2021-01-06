#include <iostream>
#include <map>
using namespace std;

long long N, P, Q;
map<long long, long long> m;

long long dfs(long long cur) {

	if (!m.count(cur)) return m[cur];
	else m[cur] = (dfs(cur / P) + dfs(cur / Q));
	return m[cur];
}

int main() {
	cin >> N >> P >> Q;

	m[0] = 1;
	printf("%lld\n", dfs(N));
	return 0;
}