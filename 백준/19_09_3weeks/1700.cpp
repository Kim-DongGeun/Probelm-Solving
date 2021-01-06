#include <iostream> // 1700 ��Ƽ�� �����층
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
			if (order[i] == multitap[j]) { // �������ʰ� ���� ��Ƽ�ǿ� �ִ��� Ȯ��
				checkMultitap = true;
				break;
			}
		}
		if (checkMultitap) continue; // ������ �������ʷ�
		else if (!checkMultitap && multitapLen < N) { // �����鼭 ��Ƽ���� �� ������ ������
			multitap[multitapLen++] = order[i];
		}
		else { // ������ ���� ���� �߿��� ���� ���߿� �����°� ��
			for (int j = 0; j < N; j++) {
				onUse[multitap[j]]++;
			}
			int count = 0; // ���� ���� �� ���� ��Ƽ�ǿ� ���� ���� ������ ++
			int index = 0;
			for (int j = i + 1; j < K; j++) {
				if (onUse[order[j]] == 1) {
					onUse[order[j]]--;
					count++;
				}
				if (count == N - 1) { // �� ���������� ã���� ��
					for (int k = 0; k < N; k++) {
						if (onUse[multitap[k]] == 1) {
							index = k;
							break;
						}
					}
					break;
				}
			}
			if(count == 0) { // ���� ���� �� �ƹ��͵� ��Ƽ�ǿ� ���� ��
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