#include <iostream>
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;

	int* answer = new int[test_case]();
	for (int i = 0; i < test_case; i++)
	{
		int A, B;
		cin >> A >> B;
		answer[i] = A + B;
	}
	for (int i = 0; i < test_case; i++)
		cout << answer[i] << endl;

	return 0;
}
