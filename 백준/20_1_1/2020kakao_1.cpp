#include <string>
#include <vector>

using namespace std;

int go(string str, int length) {
	string newStr = "";
	int cnt = 1, j;
	for (int i = 0; i < str.length();) {
		cnt = 1;
		for (j = i + length; j < str.length(); j += length) {
			if (str.substr(i, length) == str.substr(j, length))
				cnt++;
			else {
				if (cnt == 1)
					newStr += str.substr(i, length);
				else
					newStr += to_string(cnt) + str.substr(i, length);
				i += cnt * length;
				break;
			}
		}
		if (j == str.length()) {
			if (cnt == 1)
				newStr += str.substr(i, length);
			else
				newStr += to_string(cnt) + str.substr(i, length);
			i += cnt * length;
		}
		else if (j > str.length()) {
			newStr += str.substr(i, str.length() - i);
			break;
		}
	}
	return newStr.length();
}

int solution(string s) {
	int answer = s.length();

	for (int i = 1; i <= s.length() / 2; i++) {
		int value = go(s, i);
		answer = answer < value ? answer : value;
	}
	return answer;
}

