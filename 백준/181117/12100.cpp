/*
	º¸·ù
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<vector<vector<int>>, int> check;
vector<vector<int>> arr(21, vector<int>(21));

int N, ans = 0;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

/*void move(int x, int y, int index, vector<vector<int>> &Copy_map)
{
	while (1) {
		int nx = x + dx[index];
		int ny = y + dy[index];
		
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !Copy_map[ny][nx]) {
			swap(Copy_map[ny][nx], Copy_map[y][x]);
			x = nx; y = ny;
		}
		else if (nx < 0 || nx >= N || ny < 0 || ny >= N || Copy_map[ny][nx] < Copy_map[y][x] || Copy_map[ny][nx] > Copy_map[y][x]) {
			nx -= dx[index];
			ny -= dy[index];

			swap(Copy_map[ny][nx], Copy_map[y][x]);
			break;
		}
		else if (Copy_map[ny][nx] == Copy_map[y][x]) {
			Copy_map[ny][nx] *= 2;
			Copy_map[y][x] = 0;
			break;
		}
	}
}*/

void dfs(int depth, vector<vector<int>> map) {

	if (depth == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans = ans < map[i][j] ? map[i][j] : ans;
		return;

	}
	
	for (int index = 0; index < 4; index++) {
		vector<vector<int>> copy_map(21, vector<int>(21));
		bool check[21][21] = {};
		switch (index) {
		case 0: //right
			copy_map = map;
			for (int i = N - 1; i >= 0; i--) {
				for (int j = 0; j < N; j++) {
					int x = i; int y = j;
					if (map[y][x] == 0) continue;
					while (1) {
						int nx = x + dx[index];
						int ny = y + dy[index];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N && !copy_map[ny][nx]) {
							swap(copy_map[ny][nx], copy_map[j][i]);
							x = nx; y = ny;
						}
						else if (nx < 0 || nx >= N || ny < 0 || ny >= N || copy_map[ny][nx] < copy_map[y][x] || copy_map[ny][nx] > copy_map[y][x]) {
							nx -= dx[index];
							ny -= dy[index];

							swap(copy_map[ny][nx], copy_map[y][x]);
							break;
						}
						else if (copy_map[ny][nx] == copy_map[y][x] && !check[ny][nx]) {
							check[ny][nx] = true;
							copy_map[ny][nx] *= 2;
							copy_map[y][x] = 0;
							break;
						}
					}
				}
			}
			dfs(depth + 1, map);
			map = copy_map;
			break;
		case 1: //up
			copy_map = map;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int x = j; int y = i;
					if (map[y][x] == 0) continue;
					while (1) {
						int nx = x + dx[index];
						int ny = y + dy[index];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N && !copy_map[ny][nx]) {
							swap(copy_map[ny][nx], copy_map[j][i]);
							x = nx; y = ny;
						}
						else if (nx < 0 || nx >= N || ny < 0 || ny >= N || copy_map[ny][nx] < copy_map[y][x] || copy_map[ny][nx] > copy_map[y][x]) {
							nx -= dx[index];
							ny -= dy[index];

							swap(copy_map[ny][nx], copy_map[y][x]);
							break;
						}
						else if (copy_map[ny][nx] == copy_map[y][x] && !check[ny][nx]) {
							check[ny][nx] = true;
							copy_map[ny][nx] *= 2;
							copy_map[y][x] = 0;
							break;
						}
					}
				}
			}
			dfs(depth + 1, map);
			map = copy_map;
			break;
		case 2: //left
			copy_map = map;
			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++) {
					int x = i; int y = j;
					if (map[y][x] == 0) continue;
					while (1) {
						int nx = x + dx[index];
						int ny = y + dy[index];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N && !copy_map[ny][nx]) {
							swap(copy_map[ny][nx], copy_map[j][i]);
							x = nx; y = ny;
						}
						else if (nx < 0 || nx >= N || ny < 0 || ny >= N || copy_map[ny][nx] < copy_map[y][x] || copy_map[ny][nx] > copy_map[y][x]) {
							nx -= dx[index];
							ny -= dy[index];

							swap(copy_map[ny][nx], copy_map[y][x]);
							break;
						}
						else if (copy_map[ny][nx] == copy_map[y][x] && !check[ny][nx]) {
							check[ny][nx] = true;
							copy_map[ny][nx] *= 2;
							copy_map[y][x] = 0;
							break;
						}
					}
				}
			}
			dfs(depth + 1, map);
			map = copy_map;
			break;
		case 3: //down
			copy_map = map;
			for (int i = N - 1; i >= 0; i--){
				for (int j = 0; j < N; j++) {
					int x = j; int y = i;
					if (map[y][x] == 0) continue;
					while (1) {
						int nx = x + dx[index];
						int ny = y + dy[index];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N && !copy_map[ny][nx]) {
							swap(copy_map[ny][nx], copy_map[j][i]);
							x = nx; y = ny;
						}
						else if (nx < 0 || nx >= N || ny < 0 || ny >= N || copy_map[ny][nx] < copy_map[y][x] || copy_map[ny][nx] > copy_map[y][x]) {
							nx -= dx[index];
							ny -= dy[index];

							swap(copy_map[ny][nx], copy_map[y][x]);
							break;
						}
						else if (copy_map[ny][nx] == copy_map[y][x] && !check[ny][nx]) {
							check[ny][nx] = true;
							copy_map[ny][nx] *= 2;
							copy_map[y][x] = 0;
							break;
						}
					}
				}
			}
			dfs(depth + 1, map);
			map = copy_map;
			break;
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			scanf("%d", &arr[i][j]);

	
	dfs(0, arr);

	printf("%d\n", ans);
	return 0;
}