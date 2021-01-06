#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	string arr[51];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	
	for (int j = 0; j < arr[0].length(); j++) {
		int cnt = 0;
		for (int i = 1; i < N; i++) {
			if (arr[0][j] == arr[i][j]) cnt++;
		}
		if (cnt == N - 1) cout << arr[0][j];
		else cout << "?";
	}
	return 0;
}