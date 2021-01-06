#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Info
{
	int num;
	int depth;
};

struct Data
{
	int Max;
	int Min;
	Data() { Max = 0, Min = 10001; }
};

struct Node
{
	int left;
	int right;
};


vector<Node> tree(10001);
vector<Data> dataArr(10001); // 깊이당 최대,최소
int nodeNum[10001]; // 각 노드의 값
int cnt = 1;
int findRoot[10001] = { 0, };

void searchTree(int node) {
	if (tree[node].left != -1)
		searchTree(tree[node].left);

	nodeNum[node] = cnt++;

	if (tree[node].right != -1)
		searchTree(tree[node].right);
}

int main() {
	int N, node, leftSub, rightSub, root, ans = 0, maxDepth = 0;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &node, &leftSub, &rightSub);
		tree[node] = { leftSub, rightSub };
		findRoot[node]++;
		findRoot[leftSub]++;
		findRoot[rightSub]++;
	}

	for (int i = 1; i <= N; i++)
		if (findRoot[i] == 1) {
			root = i;
		}

	searchTree(root);
	
	queue<Info> q;
	q.push({ root,1 });

	while (!q.empty()) {
		Info temp = q.front();
		q.pop();
		maxDepth = max(maxDepth, temp.depth);

		if (tree[temp.num].left != -1) {
			dataArr[temp.depth].Max = max(dataArr[temp.depth].Max, nodeNum[tree[temp.num].left]);
			dataArr[temp.depth].Min = min(dataArr[temp.depth].Min, nodeNum[tree[temp.num].left]);
			q.push({ tree[temp.num].left , temp.depth + 1 });
		}
		if (tree[temp.num].right != -1) {
			dataArr[temp.depth].Max = max(dataArr[temp.depth].Max, nodeNum[tree[temp.num].right]);
			dataArr[temp.depth].Min = min(dataArr[temp.depth].Min, nodeNum[tree[temp.num].right]);
			q.push({ tree[temp.num].right , temp.depth + 1 });
		}
	}
	int index = 0;
	for (int i = 1; i < maxDepth; i++){
		if (ans < dataArr[i].Max - dataArr[i].Min) {
			ans = dataArr[i].Max - dataArr[i].Min;
			index = i;
		}
	}
		
	
	printf("%d %d\n", index + 1, ans + 1);
	return 0;
}