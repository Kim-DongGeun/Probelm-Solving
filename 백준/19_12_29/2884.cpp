#include <iostream>
using namespace std;

int main() {
	int H, M;
	scanf_s("%d %d", &H, &M);

	if (M >= 45) {
		printf("%d %d\n", H, M - 45);
	}
	else {
		if (H == 0) {
			printf("23 %d\n", M + 15);
		}
		else {
			printf("%d %d\n", H - 1, M + 15);
		}
	}
	return 0;
}