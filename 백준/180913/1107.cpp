/*
	idea : �׽�Ʈ ���̽��� �۱⶧���� ó������ ��� ��츦 �� ������ ��ã��
		   ä�μ����� + - �����ϴ� ���� + - ������ ä�������ϴ� ����� �������� ã��
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int remote[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int M, a;
	int N;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		remote[a] = -1; //���峭�� ǥ��
	}


	int Min = INT32_MAX;
	for (int i = 0; i < 1000000; i++)
	{
		int correct = 0;
		int num = i;

		if (i == 0 && remote[0] != -1) //ä�� 0���� ���� +�� �����ϴ� ���
			correct++;
		else if (i == 0 && remote[0] == -1)
			correct = -1;
		
		bool out = false;
		while (num > 0)
		{
			if (remote[num % 10] == -1)
			{
				out = true;
				break;
			}
			else
			{
				correct++;
				num /= 10;
			}
		}
		
		if (!out && correct > 0)
		{
			int sum = correct + abs(N - i);

			Min = min(Min, sum);
		}
	}

	//ä�μ����� �̵��ϴ� ���� + - �θ� �̵��ϴ� ��� �� �������� ��
	printf("%d\n", min(Min, abs(100 - N)));
	return 0;
}