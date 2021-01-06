#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;

	int* answer = new int[test_case]();

	for (int j = 0; j < test_case; j++)
	{
		int index = 0;
		string input, temp = "";
		cin.clear();
		cin.ignore();
		getline(cin, input);

		while (index <= input.length())
		{
			if (index != input.length() && input[index] != ' ')
				temp += input[index];
			else
			{
				if (atoi(temp.c_str()) % 2 == 1)
					answer[j] += atoi(temp.c_str());
				temp.clear();
			}
			index++;
		}
	}
	for (int i = 0; i < test_case; i++)
		cout << "#" << i + 1 << " " << answer[i] << endl;
	return 0;
}