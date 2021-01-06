#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Data { int x, y; };

vector<Data> arr;
vector<bool> check(101);

int main() {
	int t, n, x, y;

	scanf_s("%d", &t);
	while (t--) {
		Data home;
		Data destination;
		arr.clear();

		scanf_s("%d", &n);
		for (int i = 0; i < n; i++) check[i] = false;
		scanf_s("%d %d", &home.x, &home.y);
		for (int i = 0; i < n; i++) {
			scanf_s("%d %d", &x, &y);
			arr.push_back({ x, y });
		}
		scanf_s("%d %d", &destination.x, &destination.y);

		bool happy = false;
		queue<Data> q;
		q.push(home);
		while (!q.empty()) {
			Data cur = q.front();
			q.pop();

			if ((abs(cur.x - destination.x) + abs(cur.y - destination.y)) <= 1000) {
				happy = true;
				break;
			}

			for (int i = 0; i < arr.size(); i++) {
				if ((abs(arr[i].x - cur.x) + abs(arr[i].y - cur.y)) <= 1000 && !check[i]) {
					check[i] = true;
					q.push({ arr[i].x, arr[i].y});
				}
			}
		}
		if (happy) printf("happy\n");
		else printf("sad\n");
	}
	return 0;
}