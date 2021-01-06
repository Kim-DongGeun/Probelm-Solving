#include <iostream>
using namespace std;

int main() {
	int B, R;
	cin >> B >> R;

	for (int i = 2; i <= (B + R) / 2; i++) {
		int tempI = i;
		int temp = (B + R) / i;
		if (((tempI - 2) * (temp - 2)) == R) {
			printf("%d %d\n", temp, tempI);
			return 0;
		}
	}
	return 0;
}