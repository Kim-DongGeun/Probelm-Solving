#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	string patten;

	cin >> N >> patten;

	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;

		int cnt = 0;

		if (str.length()  >= patten.length() - 1)
			cnt = str.length() - patten.length();
		else {
			cout << "NE" << '\n';
			continue;
		}

		bool DA = true;
		int index = 0;
		for (int j = 0; j < patten.length(); j++) {
			if (patten[j] == '*') {
				index += cnt;
			}
			else {
				if (patten[j] != str[index]) {
					cout << "NE" << '\n';
					DA = false;
					break;
				}
			}
			index++;
		}
		if (DA) cout << "DA" << '\n';
	}
	return 0;
}