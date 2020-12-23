#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string n;
int arr[10] = { 0, };

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n.length(); i++) {
		arr[n[i] - '0']++;
	}

	int temp = (arr[6] + arr[9]) % 2 == 1 ? (arr[6] + arr[9] + 1) / 2 : (arr[6] + arr[9]) / 2;
	arr[6] = arr[9] = temp;
	sort(arr, arr + 10);
	cout << arr[9];
	return 0;
}