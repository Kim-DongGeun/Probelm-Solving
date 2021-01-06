#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int visited[2001][2001];
int N;
vector<int> Left, Right;
int MAX = 0;


int dfs(int leftIndex, int rightIndex) {
	if (leftIndex == -1 || rightIndex == -1) {
		return 0;
	}
	if (visited[leftIndex][rightIndex] != -1) return visited[leftIndex][rightIndex];

	visited[leftIndex][rightIndex] = max(dfs(leftIndex - 1, rightIndex - 1), dfs(leftIndex - 1, rightIndex));
	if(Left[leftIndex] > Right[rightIndex])
		visited[leftIndex][rightIndex] = max(visited[leftIndex][rightIndex], dfs(leftIndex, rightIndex - 1) + Right[rightIndex]);


	return visited[leftIndex][rightIndex];
}

int main() {
	cin >> N;
	Left.resize(N);
	Right.resize(N);
	for (int i = 0; i < N; i++)
		cin >> Left[i];
	for (int i = 0; i < N; i++)
		cin >> Right[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = -1;

	reverse(Left.begin(), Left.end());
	reverse(Right.begin(), Right.end());



	printf("%d\n", dfs(N - 1, N - 1));
	return 0;
}