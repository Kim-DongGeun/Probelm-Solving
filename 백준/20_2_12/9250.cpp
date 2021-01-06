#include <iostream>
#include <algorithm>
using namespace std;

string arr[1001];

int main() {
	int N, Q;
	string input;
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> input;

		bool FIND = false;
		for (int k = 0; k < N; k++) {
			if (input.find(arr[k]) != string::npos) {
				cout << "YES\n";
				FIND = true;
				break;
			}
		}
		if (!FIND) cout << "NO\n";
	}
	return 0;
}