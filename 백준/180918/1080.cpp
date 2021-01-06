/*
	idea : hight - 2, width - 2 ���� ĭ���� ���ϸ鼭 �ٲپ�� ���� ���ϸ� ������ �ּڰ��� ����
*/
#include <iostream>
using namespace std;

int arr[50][50];
int temp[50][50];

void Change(int x, int y) 
{
	for(int i = y ; i < y + 3; i++)
		for (int j = x; j < x + 3; j++)
			arr[i][j] = arr[i][j] == 0 ? 1 : 0;
}

int main()
{
	int hight, width;

	scanf("%d %d", &hight, &width);

	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			scanf("%1d", &arr[i][j]);

	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			scanf("%1d", &temp[i][j]);

	int ans = 0;
	for (int i = 0; i < hight - 2; i++) {
		for (int j = 0; j < width - 2; j++)
		{
			if (arr[i][j] != temp[i][j]) //�ٸ��� �ٲ�
			{
				Change(j, i);
				ans++;
			}
		}
	}

	bool answer = true;
	for (int i = 0; i < hight; i++) {
		for (int j = 0; j < width; j++)
			if (arr[i][j] != temp[i][j]) {
				answer = false;
				break;
			}
		if (!answer) break;
	}

	if (answer) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}