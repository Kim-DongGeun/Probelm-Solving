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

int ans = 0;
int n;
vector<int> arr[9];

void cal(vector<int>& order) {
	vector<int> temp;
	for (int x : order) temp.push_back(x);
	temp.insert(temp.begin() + 3, 0);

	int inning = 0;
	int i = 0;
	int sum = 0;
	while (inning < n) {
		bool baseball[3] = { false,};
		int cnt = 0;
		while (cnt < 3) {
			switch (arr[temp[i]][inning])
			{
			case 1:
				if (baseball[2]) sum++;
				baseball[2] = baseball[1];
				baseball[1] = baseball[0];
				baseball[0] = true;
				break;
			case 2:
				if (baseball[2]) sum++;
				if (baseball[1]) sum++;
				baseball[2] = baseball[0];
				baseball[1] = true;
				baseball[0] = false;
				break;
			case 3:
				if (baseball[2]) sum++;
				if (baseball[1]) sum++;
				if (baseball[0]) sum++;
				baseball[2] = true;
				baseball[1] = false;
				baseball[0] = false;
				break;
			case 4:
				if (baseball[2]) sum++;
				if (baseball[1]) sum++;
				if (baseball[0]) sum++;
				sum++;
				baseball[2] = baseball[1] = baseball[0] = false;
				break;
			case 0:
				cnt++;
				break;
			default:
				break;
			}
			i = (i + 1) % 9;
		}
		inning++;
	}
	ans = max(ans, sum);
}

void permutation(int s, int e, vector<int>& order) {
	if (s == e) {
		cal(order);
	}

	for (int i = s; i <= e; i++) {
		swap(order[s], order[i]);
		permutation(s + 1, e, order);
		swap(order[s], order[i]);
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			int x;
			cin >> x;
			arr[j].push_back(x);
		}
	}

	vector<int> order(8);
	for (int i = 1; i < 9; i++) order[i - 1] = i;

	permutation(0, 7, order);

	cout << ans;
	return 0;
}