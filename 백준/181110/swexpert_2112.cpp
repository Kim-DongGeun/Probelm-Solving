/*
	idea : ���Ʈ ������ �ִ��� ���� �Ҽ� �ִ� ���������� ����
*/
#include <iostream>
using namespace std;

int D, W, K, ans;
int map[14][21];


bool isfound() {
	bool pass;
	int count, length;
	for (int i = 0; i < W; i++) {
		count = 1;
		pass = false;
		for (int j = 0; j < D-1; j++) {
			if (map[j][i] == map[j + 1][i]) count++;
			else count = 1;
			if (count == K) {
				pass = true; break;
			}
		}
		if (!pass) return false;
	}
	return pass;
}

void dfs(int height, int count) {
	if (isfound()){
		ans = ans < count ? ans : count; return;
	}
	if (count > ans || height >= D) return;

	int save[21];
	for (int j = 0; j < W; j++)
		save[j] = map[height][j];

	for (int j = 0; j < W; j++) //B����
		map[height][j] = 1;
	dfs(height + 1, count + 1);

	for (int j = 0; j < W; j++) //A����
		map[height][j] = 0;
	dfs(height + 1, count + 1);

	for (int j = 0; j < W; j++) //����
		map[height][j] = save[j];

	dfs(height + 1, count); //�๰���Ծ��� ���
}


int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d", &D, &W, &K);
		ans = INT32_MAX;

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++)
				scanf("%d", &map[i][j]);
		}
		dfs(0, 0);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}