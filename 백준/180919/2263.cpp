/*
	idea : postorder에서 노드의 위치를 알아내면서 왼쪽 오른쪽 나누어서 탐색한다.
*/
#include <iostream>
using namespace std;

int postorder[100000];
int inorder[100000];
int position[100001];

void solve(int in_start, int in_end, int post_start, int post_end)
{
	if (in_start > in_end || post_start > post_end) return;
	int root = postorder[post_end];
	printf("%d ", root);
	int p = position[root];

	int left = p - in_start;
	solve(in_start, p - 1, post_start, post_start + left - 1); //왼쪽탐색
	solve(p + 1, in_end, post_start + left, post_end - 1); //오른쪽탐색
}

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
	for (int j = 0; j < N; j++) scanf("%d", &postorder[j]);
	for (int i = 0; i < N; i++) position[inorder[i]] = i; //각 노드의 인덱스를 저장함

	solve(0, N - 1, 0, N - 1);

	return 0;

}

