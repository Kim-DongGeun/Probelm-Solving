#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		string temp;
		cin >> temp;
		cout << atoi(temp.substr(0, 1).c_str()) + atoi(temp.substr(2, 1).c_str()) << endl;
	}
	return 0;
}
