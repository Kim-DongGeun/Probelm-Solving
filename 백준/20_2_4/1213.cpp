#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[30] = { 0, };

int main() {
	string input;
	cin >> input;

	cout << 'Z' - 'A';

 	for (int i = 0; i < input.length(); i++)
		arr[input[i] - 'A']++;

	int index = -1;
	for (int i = 0; i < 30; i++)
		if (arr[i] % 2 == 1) {
			if (index == -1) {
				index = i;
			}
			else {
				printf("I'm Sorry Hansoo\n");
				return 0;
			}
		}

	string temp = "";
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < arr[i] / 2; j++)
			temp += 'A' + i;
	}
	cout << temp;
	if (index != -1)
		cout << char('A' + index);
	reverse(temp.begin(), temp.end());
	cout << temp << '\n';
	return 0;
}