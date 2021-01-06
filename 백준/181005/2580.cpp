/*
	idea : 입력되는 숫자들을 전부체크해두고 빈칸에 모든 숫자를 넣어본다.
*/
#include <iostream>
using namespace std;

int arr[10][10];
bool check1[10][10]; //row 체크
bool check2[10][10]; //col 체크
bool check3[10][10]; //작은 사각형 체크

void go(int n)
{
	if (n == 81)
	{
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", arr[i][j]);
			printf("\n");
		}
		exit(0);
	}

	int y = n / 9;
	int x = n % 9;

	if (arr[y][x] != 0) {
		go(n + 1);
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (check1[y][i] == false && check2[x][i] == false && check3[(y / 3) * 3 + x / 3][i] == false)
			{
				arr[y][x] = i;
				check1[y][i] = true;
				check2[x][i] = true;
				check3[(y / 3) * 3 + x / 3][i] = true;
				go(n + 1);
				arr[y][x] = 0;
				check1[y][i] = false;
				check2[x][i] = false;
				check3[(y / 3) * 3 + x / 3][i] = false;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0)
			{
				check1[i][arr[i][j]] = true;
				check2[j][arr[i][j]] = true;
				check3[(i / 3) * 3 + j / 3][arr[i][j]] = true;
			}
		}

	go(0);
	return 0;
}