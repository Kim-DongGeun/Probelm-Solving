#include <iostream>
#include <string>
using namespace std;

string input;
int N;
long long MAX = INT32_MIN;

long long cal(string str) {
	long long ans;
	string newStr = "";
	for (int i = 0; i < str.length();) {
		if (str[i] == '(') {
			switch (str[i + 2]) {
			case '+':
				newStr += to_string((str[i + 1] - '0') + (str[i + 3] - '0'));
				break;
			case '*':
				newStr += to_string((str[i + 1] - '0') * (str[i + 3] - '0'));
				break;
			case '-':
				newStr += to_string(((str[i + 1] - '0') - (str[i + 3] - '0')));
				break;
			}
			i += 5;
		}
		else {
			newStr += str[i];
			i++;
		}
	}
	int i = 1;
	if (newStr[0] == '-') {
		ans = -(newStr[1] - '0');
		i++;
	}
	else {
		ans = newStr[0] - '0';
		if (newStr[1] >= '0' && newStr[1] <= '9') {
			ans = 10 * ans + (newStr[1] - '0');
			i++;
		}
	}
	for (; i < newStr.length(); i += 2) {
		if (newStr[i + 1] == '-') {
			switch (newStr[i]) {
			case '+':
				ans = ans - (long long)(newStr[i + 2] - '0');
				break;
			case '*':
				ans = -ans * (long long)(newStr[i + 2] - '0');
				break;
			case '-':
				ans = ans + (long long)(newStr[i + 2] - '0');
				break;
			}
			i++;
		}
		else if (i + 2 < newStr.length() && newStr[i + 2] >= '0' && newStr[i + 2] <= '9') {
			switch (newStr[i]) {
			case '+':
				ans = ans + (long long)((newStr[i + 1] - '0') * 10 + (newStr[i + 2] - '0'));
				break;
			case '*':
				ans = ans * (long long)((newStr[i + 1] - '0') * 10 + (newStr[i + 2] - '0'));
				break;
			case '-':
				ans = ans - (long long)((newStr[i + 1] - '0') * 10 + (newStr[i + 2] - '0'));
				break;
			}
			i++;
		}
		
		else {
			switch (newStr[i]) {
			case '+':
				ans = ans + (long long)(newStr[i + 1] - '0');
				break;
			case '*':
				ans = ans * (long long)(newStr[i + 1] - '0');
				break;
			case '-':
				ans = ans - (long long)(newStr[i + 1] - '0');
				break;
			}
		}
	}
	return ans;

}

void dfs(int depth, string str, pair<int, bool> left) {
	if (depth == N) {
		if (left.second) str += ')';
		long long temp = cal(str);
		MAX = MAX < temp ? temp : MAX;
		return;
	}

	if (!left.second && (input[depth] == '+' || input[depth] == '-' || input[depth] == '*'))
		dfs(depth + 1, str + input[depth], left); // 연산자 추가
	else {
		if (left.second && str.length() - left.first == 4)
			dfs(depth, str + ")", { -1, false }); // 괄호닫기
		else
			dfs(depth + 1, str + input[depth], left); // 숫자추가
		if(!left.second && N - depth >= 3)
			dfs(depth, str + "(", { str.length(), true }); // 괄호열기
	}
}

int main() {
	cin >> N;
	cin >> input;

	dfs(0, "", { -1, false });

	cout << MAX << '\n';
	return 0;
}