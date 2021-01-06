/*
	idea : 가로세로가 짝수이면 한칸을 빼고 돌아야됨 그 한칸이 최소가 되는 칸을 찾아서 뺴고 전부 순회
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int map[1001][1001];

int main()
{
	int R, C;
	string ans = "";
	scanf("%d %d", &R, &C);
	 
	int Min = 1001;
	int x, y;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
			if ((i + j) % 2 == 1 && Min != min(Min, map[i][j]))
			{
				Min = min(Min, map[i][j]);
				y = i;
				x = j;
			}
		}
	}
	
	if (R % 2 == 0 && C % 2 == 0)
	{
		string s = "";
		int x1 = 0, y1 = 0, x2 = C - 1, y2 = R - 1;
		while (y2 - y1 > 1) //세로 길이 줄이기
		{
			if (y1 / 2 < y / 2)
			{
				for (int i = 1; i < C; i++)
					ans += "R";
				ans += "D";
				for (int i = 1; i < C; i++)
					ans += "L";
				ans += "D";
				y1 += 2;
			}
			if (y2 / 2 > y / 2)
			{
				for (int i = 1; i < C; i++)
					s += "R";
				s += "D";
				for (int i = 1; i < C; i++)
					s += "L";
				s += "D";
				
				y2 -= 2;
			}
		}
		while (x2 - x1 > 1) //가로 길이 줄이기
		{
			if (x1 / 2 < x / 2)
			{
				ans += "DRUR";
				x1 += 2;
			}
			if (x2 / 2 > x / 2)
			{
				s += "DRUR";
				x2 -= 2;
			}
		}

		if (x == x1 + 1) ans += "DR";
		else ans += "RD";

		reverse(s.begin(), s.end());
		ans += s;
	}
	else if(C % 2 == 1)
	{
		for (int i = 0; i < C; i++)
		{
			if (i % 2 == 0) {
				for (int j = 1; j < R; j++)
					ans += "D";
			}
			else
			{
				for (int j = 1; j < C; j++)
					ans += "U";
			}
			if (i != C-1)
				ans += "R";
		}
	}
	else if (R % 2 == 1)
	{
		for (int i = 0; i < R; i++)
		{
			if (i % 2 == 0) {
				for (int j = 1; j < C; j++)
					ans += "R";
			}
			else
			{
				for (int j = 1; j < C; j++)
					ans += "L";
			}
			if (i != R - 1)
				ans += "D";
		}
	}


	cout << ans << "\n";
	return 0;
}