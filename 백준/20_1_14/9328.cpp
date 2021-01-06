#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct info { int x, y; };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int T, h, w, cnt;
char Map[101][101];
bool check[101][101];
vector<char> keys;

void dfs(int x, int y) {
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= w || ny >= h || check[ny][nx]) continue;
		else if (Map[ny][nx] == '.' || Map[ny][nx] == '$') {
			if (Map[ny][nx] == '$') {
				Map[ny][nx] = '.';
				cnt++;
			}
			check[ny][nx] = true;
			dfs(nx, ny);
		}
		else if (Map[ny][nx] >= 97 && Map[ny][nx] <= 122) {
			keys.push_back(Map[ny][nx]);
			Map[ny][nx] = '.';
			check[ny][nx] = true;
			dfs(nx, ny);
		}
	}
}

int main() {
	string input;
	vector<info> start;
	int ans;
	cin >> T;
	for (int t = 0; t < T; t++) {
		start.clear();
		cnt = 0;
		cin >> h >> w;
		for (int i = 0; i < h; i++){
			cin >> input;
			for (int j = 0; j < w; j++) Map[i][j] = input[j];
			if (i == 0 || i == h - 1) {
				for (int k = 0; k < input.length(); k++) {
					if (input[k] == '.' || input[k] == '$') {
						if (input[k] == '$') {
							cnt++;
							Map[i][k] = '.';
						}
						start.push_back({ k,i });
					}
					else if (input[k] >= 97 && input[k] <= 122) {
						keys.push_back(input[k]);
						Map[i][k] = '.';
						start.push_back({ k,i });
					}
				}
			}
			else {
				if (input[0] == '.' || input[0] == '$') {
					if (input[0] == '$') {
						cnt++;
						Map[i][0] = '.';
					}
					start.push_back({ 0,i });
				}
				else if (input[0] >= 97 && input[0] <= 122) {
					keys.push_back(input[0]);
					Map[i][0] = '.';
					start.push_back({ 0,i });
				}
				if (input[w - 1] == '.' || input[w - 1] == '$') {
					if (input[w - 1] == '$') {
						cnt++;
						Map[i][w - 1] = '.';
					}
					start.push_back({ w - 1, i });
				}
				else if (input[w - 1] >= 97 && input[w - 1] <= 122) {
					keys.push_back(input[w - 1]);
					Map[i][w - 1] = '.';
					start.push_back({ w - 1, i });
				}
			}
		}

		cin >> input;
		for (int i = 0; i < keys.size(); i++) {
			for (int j = 0; j < h; j++)
				for (int k = 0; k < w; k++)
					if (Map[j][k] == keys[i] - 32) {
						Map[j][k] = '.';
						if (j == 0 || k == 0 || j == h - 1 || k == w - 1) start.push_back({ k,j });
					}
		}
		if (input[0] != '0') { // 기존의 키로 문열기
			for (int i = 0; i < input.length(); i++) {
				for (int j = 0; j < h; j++)
					for (int k = 0; k < w; k++)
						if (Map[j][k] == input[i] - 32) {
							Map[j][k] = '.';
							if (j == 0 || k == 0 || j == h - 1 || k == w - 1) start.push_back({ k,j });
						}
			}
		}
		ans = 0;
		while (true) {
			memset(check, false, sizeof(check));
			for (int i = 0; i < start.size(); i++) {
				if (!check[start[i].y][start[i].x]) {
					check[start[i].y][start[i].x] = true;
					dfs(start[i].x, start[i].y);
				}
			}
			ans = ans < cnt ? cnt : ans;

			bool out = true;
			for (int i = 0; i < keys.size(); i++) {
				for (int j = 0; j < h; j++)
					for (int k = 0; k < w; k++)
						if (Map[j][k] == keys[i] - 32) {
							Map[j][k] = '.';
							if (j == 0 || k == 0 || j == h - 1 || k == w - 1) start.push_back({ k,j });
							out = false;
						}
			}
			if (out) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}