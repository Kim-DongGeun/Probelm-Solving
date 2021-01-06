#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
pair<long long, long long> publications[200001];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) 
		cin >> publications[i].first;
	for (int i = 0; i < N; i++)
		cin >> publications[i].second;

	sort(publications, publications + N); // 정렬
	priority_queue<long long> pq;

	long long time = 0;
	long long ans = 0;
	long long val = publications[0].first;
	for (int i = 0; i < N || !pq.empty();) {
		while(val == publications[i].first) { // 현재값이랑 같으면 큐에 넣기
			pq.push(publications[i].second);
			time += publications[i].second;
			i++;
		}

		time -= pq.top();
		pq.pop();
		ans += time;
		val++;

		if (pq.empty()) val = publications[i].first;
	}

	printf("%lld\n", ans);

	return 0;
}