#include <iostream>
using namespace std;

int main()
{
	int test_case, A, B;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		cin >> A >> B;
		cout << "Case #" << i + 1 << ": " << A << " + " << B << " = " << A + B << endl;
	}
	return 0;

}