/*
	idea : 테스트 케이스가 작기때문에 처음부터 모든 경우를 다 따져서 답찾음
		   채널선택후 + - 조정하는 경우와 + - 만으로 채널조정하는 경우중 작은것을 찾음
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
		remote[a] = -1; //고장난거 표시
	}


	int Min = INT32_MAX;
	for (int i = 0; i < 1000000; i++)
	{
		int correct = 0;
		int num = i;

		if (i == 0 && remote[0] != -1) //채널 0으로 가서 +로 증가하는 경우
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

	//채널선택후 이동하는 경우와 + - 로만 이동하는 경우 중 작은것이 답
	printf("%d\n", min(Min, abs(100 - N)));
	return 0;
}