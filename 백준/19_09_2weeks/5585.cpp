#include <iostream>
using namespace std;

int main()
{
	int arr[6] = { 500,100,50,10,5,1 };
	int N, index = 0;
	scanf_s("%d", &N);

	int exchange = 1000 - N;
	int ans = 0;

	while (exchange > 0) {
		if (exchange / arr[index] > 0) {
			ans += exchange / arr[index];
			exchange %= arr[index];
		}
		index++;
	}
	printf("%d\n", ans);

	return 0;
}