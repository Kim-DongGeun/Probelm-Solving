#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define END 51

vector<int> arr[51];
vector<int> root;
int ans = 0;

void dfs(int cur) {
	if (arr[cur].size() == 0 || (arr[cur].size() == 1 && arr[cur][0] == END)) {
		ans++;
		return;
	}

	for (int i = 0; i < arr[cur].size(); i++) {
		if (arr[cur][i] != END) dfs(arr[cur][i]);
	}
}

int main() {
	int N, parent;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> parent;
		if (parent == -1) root.push_back(i);
		else arr[parent].push_back(i);
	}
	int target;
	cin >> target;


	for (int i = 0; i < 51; i++)
		for (auto iter = arr[i].begin(); iter != arr[i].end(); iter++) {
			if ((*iter) == target) {
				(*iter) = END;
				break;
			}
		}

	for(int i = 0 ; i< root.size(); i++)
		if(root[i] != target)
			dfs(root[i]);

	cout << ans << '\n';
	return 0;
}