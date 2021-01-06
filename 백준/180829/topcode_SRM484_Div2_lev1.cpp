#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//bitÀüÃ¼Å½»ö
class NumberMagicEasy
{
public:
	int theNumber(string answer)
	{
		int A[] = { 1,2,3,4,5,6,7,8 };
		int B[] = { 1,2,3,4,9,10,11,12 };
		int C[] = { 1,2,5,6,9,10,13,14 };
		int D[] = { 1,3,5,7,9,11,13,15 };

		for (int i = 1; i <= 16; i++)
		{
			if (Check(A, i) != answer[0])continue;
			if (Check(B, i) != answer[1])continue;
			if (Check(C, i) != answer[2])continue;
			if (Check(D, i) != answer[3])continue;
			return i;
		}
		return 0;
	}

	char Check(int x[], int num)
	{
		for (int i = 0; i < 8; i++)
			if (x[i] == num)return 'Y';
		return 'N';
	}

	int theNumber(string answer)
	{
		string c[4] =
		{
			"YYYYYYYYNNNNNNNN",
			"YYYYNNNNYYYYNNNN",
			"YYNNYYNNYYNNYYNN",
			"YNYNYNYNYNYNYNYN"
		};

		for (int i = 0; i < 16; i++)
		{
			string temp = "";
			for (int i = 0; i < 4; i++) temp += c[j][i];
			if (temp == answer) return i + 1;
		}
	}
};