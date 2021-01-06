#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	bool checkUnderBar = false;
	bool checkUpper = false;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '_') {
			if (i + 1 < str.length() && (str[i + 1] == '_' || (str[i + 1] >= 'A' && str[i+1] <= 'Z'))) {
				cout << "Error!\n";
				return 0;
			}
			checkUnderBar = true;
		}
		else if (str[i] < 'a') checkUpper = true;
	}

	if ((checkUnderBar && checkUpper) || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_' || str[str.length() - 1] == '_')
		cout << "Error!\n";
	else if (checkUnderBar) { // C

		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				cout << "Error!\n";
				return 0;
			}
			else if (str[i] == '_') {
				if (i == 0) continue;
				cout << (char)(str[i + 1] - ('a' - 'A'));
				i++;
			}
			else {
				cout << str[i];
			}
		}
	}
	else if (checkUpper) { // java
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '_') {
				cout << "Error!\n";
				return 0;
			}
			if (str[i] < 'a') {
				cout << '_' << (char)(str[i] + ('a' - 'A'));
			}
			else {
				cout << str[i];
			}
		}
	}
	else
		cout << str;
	return 0;
}