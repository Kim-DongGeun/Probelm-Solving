#include <iostream>
using namespace std;

int main()
{
	int month, day, sum = 0;
	cin >> month >> day;

	for (int i = 1; i <= month - 1; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 ||
			i == 8 || i == 10 || i == 12)
			sum += 31;
		else if (i == 2)
			sum += 28;
		else
			sum += 30;
	}
	sum += day - 1;
	switch (sum % 7) {
	case 0:
		cout << "MON\n";
		break;
	case 1:
		cout << "TUE\n";
		break;
	case 2:
		cout << "WED\n";
		break;
	case 3:
		cout << "THU\n";
		break;
	case 4:
		cout << "FRI\n";
		break;
	case 5:
		cout << "SAT\n";
		break;
	case 6:
		cout << "SUN\n";
		break;
	}
	return 0;
}