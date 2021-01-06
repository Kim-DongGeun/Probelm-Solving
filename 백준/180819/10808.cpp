#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	int arr[26] = { 0, };
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		switch (input[i])
		{
		case 97:
			arr[0]++;
			break;
		case 98:
			arr[1]++;
			break;
		case 99:
			arr[2]++;
			break;
		case 100:
			arr[3]++;
			break;
		case 101:
			arr[4]++;
			break;
		case 102:
			arr[5]++;
			break;
		case 103:
			arr[6]++;
			break;
		case 104:
			arr[7]++;
			break;
		case 105:
			arr[8]++;
			break;
		case 106:
			arr[9]++;
			break;
		case 107:
			arr[10]++;
			break;
		case 108:
			arr[11]++;
			break;
		case 109:
			arr[12]++;
			break;
		case 110:
			arr[13]++;
			break;
		case 111:
			arr[14]++;
			break;
		case 112:
			arr[15]++;
			break;
		case 113:
			arr[16]++;
			break;
		case 114:
			arr[17]++;
			break;
		case 115:
			arr[18]++;
			break;
		case 116:
			arr[19]++;
			break;
		case 117:
			arr[20]++;
			break;
		case 118:
			arr[21]++;
			break;
		case 119:
			arr[22]++;
			break;
		case 120:
			arr[23]++;
			break;
		case 121:
			arr[24]++;
			break;
		case 122:
			arr[25]++;
			break;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}