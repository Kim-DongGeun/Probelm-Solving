/*
	제대로한거같은데 출력초과뜸
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	string A, T;
	vector<char> L(300000, '0');
	vector<char> R(300000, '0');

	cin >> A >> T;

	int index = 0;
	int rindex = A.length() - 1;
	int lI = 0, LI = 0, RI = 0;
	int rI = T.length() - 1;
	int check = 0;
	bool change = false;
	while (rI >= lI)
	{
		if (!change) //왼쪽에서 부터 찾기
		{
			L[LI] = T[lI++];
			if (L[LI] == A[index++]) check++;
			else {
				if (L[LI] == A[0]) {
					check = 1; index = 1;
				}
				else {
					check = 0; index = 0;
				}
			}

			if (check == A.length())
			{
				while(check--) L[LI--] = '0';
				index = 0;
				check = 0;
				change = true;
				for (int i = 0; i < RI; i++) {
					if (R[RI] == A[rindex--]) check++;
					else {
						if (R[RI] == A[A.length() - 1]) {
							check = 1; rindex = A.length() - 2;
						}
						else {
							check = 0; rindex = A.length() - 1;
						}
					}
				}
			}
			LI++;
		}
		else //오른쪽에서 부터 찾기
		{
			R[RI] = T[rI--];
			if (R[RI] == A[rindex--]) check++;
			else {
				if (R[RI] == A[A.length() - 1]) {
					check = 1; rindex = A.length() - 2;
				}
				else {
					check = 0; rindex = A.length() - 1;
				}
			}

			if (check == A.length()) {
				while (check--) R[RI--] = '0';
				rindex = A.length() - 1;
				check = 0;
				change = false;
				for (int i = 0; i < LI; i++) {
					if (L[i] == A[index++]) check++;
					else {
						if (L[i] == A[0]) {
							check = 1; index = 1;
						}
						else {
							check = 0; index = 0;
						}
					}
				}
			}
			RI++;
		}
	}

	check = 0;
	rindex = A.length() - 1;

	for (int i = 0; i < RI; i++) {
		if (R[i] == A[rindex--]) check++;
		else {
			if (R[i] == A[A.length() - 1]) {
				check = 1; rindex = A.length() - 2;
			}
			else {
				check = 0; rindex = A.length() - 1;
			}
		}
	}
	while (LI > 0)
	{
		R[RI] = L[--LI];
		if (R[RI] == A[rindex--]) check++;
		else {
			if (R[RI] == A[A.length() - 1]) {
				check = 1; rindex = A.length() - 2;
			}
			else {
				check = 0; rindex = A.length() - 1;
			}
		}

		if (check == A.length()) {
			while (check--) R[RI--] = '0';
			check = 0;
			rindex = A.length() - 1;
		}
		RI++;
	}

	for (int i = RI - 1; i >= 0; i--)
		printf("%c", R[i]);
	printf("\n");
	return 0;	
}