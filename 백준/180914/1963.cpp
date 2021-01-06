/*
	idea : 10000���� �Ҽ��� ���� ã�� ���� ���� ���ڿ��� ���ڸ��� �ϳ��� �ٲ㼭
		   �Ҽ����� �Ǻ��ϰ� �湮���� �ʾ����� ť�� �ִ� ������� ��
		   �ִ� �Ÿ��� bfs
*/
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

bool arr[10000];
int check[10000] = { 0 };

int changeNum(int num, int index, int digit) //�ش� �ε����� ���ڸ� �ٲ�
{
	if (index == 0 && digit == 0)
		return -1;

	string temp = to_string(num);
	temp[index] = digit + '0';

	return stoi(temp);
}

int main()
{
	for (int i = 2; i <= 9999; i++)
		arr[i] = true;

	for (int i = 2;i <= 9999; i++) //�����佺�׳׽��� ü �Ҽ��Ǻ�
	{
		if (arr[i] == 0)continue;
		for (int j = i + i; j <= 9999; j += i) arr[j] = false;
	}

	int T;
	scanf("%d", &T);

	while (T--)
	{
		int A, B;
		scanf("%d %d", &A, &B);

		for (int i = 1; i < 10000; i++)
			check[i] = 0;
		
		queue<int> q;
		q.push(A);
		check[A] = 1; //üũ�� �ǹ̷� 1�� ǥ����

		bool out = false;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			if (x == B) { //Ÿ�ٿ� �����ϸ� Ż��
				out = true;
				break;
			}

			for (int i = 0; i < 4; i++) //4���� �ڸ� ����
			{
				for (int j = 0; j < 10; j++) // 0~9 ����
				{
					int next = changeNum(x, i, j); //���ڸ� �ٲ� ����

					if (next != -1 && arr[next] == true && !check[next])//�湮���ϰ� �Ҽ��̸�
					{
						check[next] = check[x] + 1;//�Ÿ� ����
						q.push(next);//ť�� ����
					}
				}
			}
		}
		if (out) printf("%d\n", check[B] - 1); //ã���� ��ó�� 1������ �M
		else printf("Impossible\n"); //��ã����
	}
	return 0;
}