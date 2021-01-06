#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int visited[2001][2001];
vector<int> Left(2001), Right(2001);



int main() {
	int N, left, right;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Left[i];
	for (int i = 0; i < N; i++)
		cin >> Right[i];

	for(int i = 0 ;i < N; i++)
		for (int j = 0; j < N; j++) {
			visited[i][j] = 
		}

	return 0;
}