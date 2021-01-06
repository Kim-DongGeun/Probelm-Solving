#include <iostream>
#include <string>
using namespace std;

int Num[6];
int ans, N;
int change;

void dfs(int cur, int count) {
	if (count == change) {
		int a = 0;
		for (int i = 0; i < N; i++) {
			a = a * 10 + Num[i];
			ans = ans < a ? a : ans;
		}
	}
	else
	{
		for (int i = cur; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (Num[i] <= Num[j]) {
					int temp = Num[i]; Num[i] = Num[j];	Num[j] = temp;
					dfs(i, count + 1);
					temp = Num[j];  Num[j] = Num[i]; Num[i] = temp;
				}
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		string num;
		cin >> num >> change;

		ans = stoi(num);
		N = num.size();
		for (int i = 0; i < N; i++) {
			Num[i] = num[i] - '0';
		}

		dfs(0, 0);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}