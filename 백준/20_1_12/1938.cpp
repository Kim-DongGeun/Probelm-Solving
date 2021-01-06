#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct info { int x, y; };
struct source { int x, y, cnt, dir; };


char order[5] = { 'U', 'D', 'L', 'R', 'T' };
bool check[3][51][51] = { false, };

int main() {
	int N;
	string input;
	vector<info> B;
	vector<info> E;
	char Map[51][51];
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < input.length(); j++) {
			Map[i][j] = input[j];
			if (Map[i][j] == 'B') {
				B.push_back({ j, i});
				Map[i][j] = '0';
			}
			else if (Map[i][j] == 'E') {
				E.push_back({ j, i});
			}
		}
	}

	int bDir, eDir;
	if (B[0].y - B[1].y == 0) bDir = 0; // 가로방향
	else bDir = 1; // 세로방향

	if (E[0].y - E[1].y == 0) eDir = 0; // 가로방향
	else eDir = 1; // 세로방향


	queue<source> q;
	q.push({ B[1].x, B[1].y, 0, bDir });
	check[bDir][B[1].y][B[1].x] = true;
	while (!q.empty()) {
		source cur = q.front();
		q.pop();

		if (cur.x == E[1].x && cur.y == E[1].y && cur.dir == eDir) {
			printf("%d\n", cur.cnt);
			return 0;
		}

		for (int i = 0; i < 5; i++) {
			switch (order[i])
			{
			case 'U':
				if (cur.dir == 0) {
					if (cur.y - 1 < 0 || cur.x - 1 < 0 || cur.x + 1 >= N || check[cur.dir][cur.y - 1][cur.x]) continue;
					if (Map[cur.y - 1][cur.x] != '1' && Map[cur.y - 1][cur.x + 1] != '1' && Map[cur.y - 1][cur.x - 1] != '1') {
						check[cur.dir][cur.y - 1][cur.x] = true;
						q.push({ cur.x, cur.y - 1, cur.cnt + 1, cur.dir });
					}
				}
				else {
					if (cur.y - 2 < 0 || check[cur.dir][cur.y - 1][cur.x]) continue;
					if (Map[cur.y - 2][cur.x] != '1') {
						check[cur.dir][cur.y - 1][cur.x] = true;
						q.push({ cur.x, cur.y - 1, cur.cnt + 1, cur.dir });
					}
				}
				break;
			case 'D':
				if (cur.dir == 0) {
					if (cur.y + 1 >= N || cur.x - 1 < 0 || cur.x + 1 >= N || check[cur.dir][cur.y + 1][cur.x]) continue;
					if (Map[cur.y + 1][cur.x] != '1' && Map[cur.y + 1][cur.x + 1] != '1' && Map[cur.y + 1][cur.x - 1] != '1') {
						check[cur.dir][cur.y + 1][cur.x] = true;
						q.push({ cur.x, cur.y + 1, cur.cnt + 1, cur.dir });
					}
				}
				else {
					if (cur.y + 2 >= N || check[cur.dir][cur.y + 1][cur.x]) continue;
					if (Map[cur.y + 2][cur.x] != '1') {
						check[cur.dir][cur.y + 1][cur.x] = true;
						q.push({ cur.x, cur.y + 1, cur.cnt + 1, cur.dir });
					}
				}
				break;
			case 'L':
				if (cur.dir == 0) {
					if (cur.x - 2 < 0 || check[cur.dir][cur.y][cur.x - 1]) continue;
					if (Map[cur.y][cur.x - 2] != '1') {
						check[cur.dir][cur.y][cur.x - 1] = true;
						q.push({ cur.x - 1, cur.y, cur.cnt + 1, cur.dir });
					}
				}
				else {
					if (cur.x - 1 < 0 || cur.y - 1 < 0 || cur.y + 1 >= N || check[cur.dir][cur.y][cur.x - 1]) continue;
					if (Map[cur.y][cur.x - 1] != '1' && Map[cur.y + 1][cur.x - 1] != '1' && Map[cur.y - 1][cur.x - 1] != '1') {
						check[cur.dir][cur.y][cur.x - 1] = true;
						q.push({ cur.x - 1, cur.y, cur.cnt + 1, cur.dir });
					}
				}
				break;
			case 'R':
				if (cur.dir == 0) {
					if (cur.x + 2 >= N || check[cur.dir][cur.y][cur.x + 1]) continue;
					if (Map[cur.y][cur.x + 2] != '1') {
						check[cur.dir][cur.y][cur.x + 1] = true;
						q.push({ cur.x + 1, cur.y, cur.cnt + 1, cur.dir });
					}
				}
				else {
					if (cur.x + 1 >= N || cur.y - 1 < 0 || cur.y + 1 >= N || check[cur.dir][cur.y][cur.x + 1]) continue;
					if (Map[cur.y][cur.x + 1] != '1' && Map[cur.y + 1][cur.x + 1] != '1' && Map[cur.y - 1][cur.x + 1] != '1') {
						check[cur.dir][cur.y][cur.x + 1] = true;
						q.push({ cur.x + 1, cur.y, cur.cnt + 1, cur.dir });
					}
				}
				break;
			case 'T':
				if (cur.dir == 0) {
					if (cur.x + 1 >= N || cur.x - 1 < 0 || cur.y + 1 >= N || cur.y - 1 < 0 || check[2][cur.y][cur.x]) continue;
					if (Map[cur.y - 1][cur.x] != '1' && Map[cur.y - 1][cur.x - 1] != '1' && Map[cur.y - 1][cur.x + 1] != '1' &&
						Map[cur.y + 1][cur.x] != '1' && Map[cur.y + 1][cur.x - 1] != '1' && Map[cur.y + 1][cur.x + 1] != '1') {
						check[2][cur.y][cur.x] = true;
						q.push({ cur.x, cur.y, cur.cnt + 1, (cur.dir + 1) % 2 });
					}
				}
				else {
					if (cur.x + 1 >= N || cur.x - 1 < 0 || cur.y + 1 >= N || cur.y - 1 < 0 || check[2][cur.y][cur.x]) continue;
					if (Map[cur.y][cur.x - 1] != '1' && Map[cur.y - 1][cur.x - 1] != '1' && Map[cur.y + 1][cur.x - 1] != '1' &&
						Map[cur.y][cur.x + 1] != '1' && Map[cur.y - 1][cur.x + 1] != '1' && Map[cur.y + 1][cur.x + 1] != '1') {
						check[2][cur.y][cur.x] = true;
						q.push({ cur.x, cur.y, cur.cnt + 1, (cur.dir + 1) % 2 });
					}
				}
				break;
			default:
				break;
			}
		}
	}
	printf("0\n");
	return 0;
}