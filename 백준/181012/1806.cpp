/*
	idea : ������ �־��� ���� ������ �ߺ���. �ڵ�� �ִ��� �����ϰ�
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M, ans = 100001, arr[100001];
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1, j = 0; i <= N; i++){
		scanf("%d", &arr[i]);
		arr[i] += arr[i - 1];
		for (; arr[i] - arr[j] >= M;j++) ans = min(ans, i - j);
	}

	printf("%d\n", ans == 100001 ? 0 : ans);
	return 0;
}