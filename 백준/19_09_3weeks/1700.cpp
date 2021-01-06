#include <iostream> // 1700 멀티탭 스케쥴링
#include <map>
using namespace std;

int main()
{
	int N, K, ans = 0, multitapLen = 0;
	int multitap[101];
	int order[101];
	map<int, int> onUse;
	scanf_s("%d %d", &N, &K);

	for (int i = 0; i < K; i++)
		scanf_s("%d", &order[i]);
	


	for (int i = 0; i < K; i++) {
		bool checkMultitap = false;
		for (int j = 0; j < multitapLen; j++) {
			if (order[i] == multitap[j]) { // 다음차례가 현재 멀티탭에 있는지 확인
				checkMultitap = true;
				break;
			}
		}
		if (checkMultitap) continue; // 있으면 다음차례로
		else if (!checkMultitap && multitapLen < N) { // 없으면서 멀티탭이 다 차있지 않을때
			multitap[multitapLen++] = order[i];
		}
		else { // 없으면 다음 차례 중에서 가장 나중에 나오는걸 뺌
			for (int j = 0; j < N; j++) {
				onUse[multitap[j]]++;
			}
			int count = 0; // 다음 차례 중 현재 멀티탭에 같은 것이 있으면 ++
			int index = 0;
			for (int j = i + 1; j < K; j++) {
				if (onUse[order[j]] == 1) {
					onUse[order[j]]--;
					count++;
				}
				if (count == N - 1) { // 젤 마지막꺼를 찾았을 때
					for (int k = 0; k < N; k++) {
						if (onUse[multitap[k]] == 1) {
							index = k;
							break;
						}
					}
					break;
				}
			}
			if(count == 0) { // 다음 차례 중 아무것도 멀티탭에 없을 때
				index = 0;
			}
			else if (count < N - 1)
			{
				for (int j = 0; j < N; j++) {
					if (onUse[multitap[j]] == 1) {
						index = j;
						break;
					}
				}
			}
			multitap[index] = order[i];
			ans++;
		}
		onUse.clear();
	}
	printf("%d\n", ans);
	return 0;
}