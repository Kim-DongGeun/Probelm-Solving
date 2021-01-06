#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, int> arr;
	int N, M;
	cin >> N >> M;

	string input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[input]++;
	}

	for (int i = 0; i < M; i++) {
		cin >> input;
		arr[input]++;
	}

	int count = 0;
	for (auto x : arr) {
		if (x.second == 2)
			count++;
	}

	cout << count << "\n";
	for (auto x : arr) {
		if (x.second == 2)
			cout << x.first << "\n";
	}

	return 0;
}