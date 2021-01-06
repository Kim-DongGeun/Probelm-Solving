#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		vector<int> q;
		int index, n, input, biggest = 0;
		cin >> n >> index;
		for (int i = 0; i < n; i++) {
			cin >> input;
			biggest = biggest < input ? input : biggest;
			q.push_back(input);
		}

		int target = q[index];
		int cnt = 0;
		int c = 0;
		while (true) {
			int cur = q[0];
			if (biggest == cur) {
				if (index == 0) { // Á¤´ä
					cnt++;
					printf("%d\n", cnt);
					break;
				}
				else { // »©±â
					q.erase(q.begin());
					cnt++;
					index--;
				}
				biggest = 0;
				for (int i = 0; i < q.size(); i++)
					biggest = biggest < q[i] ? q[i] : biggest;
			}
			else {// »©¼­ µÚ·Î
				if (cur == target && index == 0) {
					index = q.size() - 1;
				}
				else index--;
				q.push_back(cur);
				q.erase(q.begin());
			}
		}
	}
	return 0;
}

