#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	char arr1[4] = "ABC";
	char arr2[5] = "BABC";
	char arr3[7] = "CCAABB";
	char input[102];

	int N;
	cin >> N;
	cin >> input;

	int ans1 = 0, ans2 = 0, ans3 = 0;

	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == arr1[i % 3]) ans1++;
		if (input[i] == arr2[i % 4]) ans2++;
		if (input[i] == arr3[i % 6]) ans3++;
	}

	int MAX = 0;
	MAX = max(max(ans1, ans2), ans3);
	printf("%d\n", MAX);
	if (ans1 == MAX) printf("Adrian\n");
	if (ans2 == MAX)printf("Bruno\n");
	if (ans3 == MAX)printf("Goran\n");

	return 0;
}