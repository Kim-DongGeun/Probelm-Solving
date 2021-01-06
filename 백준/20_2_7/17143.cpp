#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Pos { int x,y, vel, dir, size; };
vector<Pos> shark;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

int main() {
	int R, C, M;
	int r, c, s, d, z;
	cin >> R >> C >> M;
	while (M--) {
		cin >> r >> c >> s >> d >> z;
		switch (d)
		{
		case 2:
			d = 3;
			break;
		case 3:
			d = 0;
			break;
		case 4:
			d = 2;
			break;
		}
		shark.push_back({ c,r,s,d,z });
	}

	
	int ans = 0;
	int person = 0;
	while(person < C){
		person++; // 사람이동

		int index = R + 1;
		for (auto cur : shark) {
			if (cur.x == person) index = index > cur.y ? cur.y : index;
		}
		if (index != R + 1) {
			for (auto iter = shark.begin(); iter != shark.end(); iter++) { // 상어 잡기
				if ((*iter).y == index && (*iter).x == person) {
					ans += (*iter).size;
					shark.erase(iter);
					break;
				}
			}
		}
		vector<Pos> tempShark;
		int visited[102][102] = { 0, };
		for (int i = 0; i < shark.size(); i++) { // 상어 이동
			int cnt = 0;
			if (shark[i].dir == 0 || shark[i].dir == 2) // 나머지 연산으로 이동거리 줄이기
				cnt = shark[i].vel % ((C - 1) * 2);
			else
				cnt = shark[i].vel % ((R - 1) * 2);

			while (cnt--) { // 한칸씩 이동
				int nx = shark[i].x + dx[shark[i].dir];
				int ny = shark[i].y + dy[shark[i].dir];
				if (nx <= 0 || ny <= 0 || nx > C || ny > R) { // 범위를 벗어날 때
					shark[i].dir = (shark[i].dir + 2) % 4; // 방향바꾸기
					nx = shark[i].x + dx[shark[i].dir];
					ny = shark[i].y + dy[shark[i].dir];
				}
				shark[i].x = nx; // 이동
				shark[i].y = ny; //
			}

			bool out = true;
			if (visited[shark[i].y][shark[i].x]) { // 그자리에 상어가 있으면 크기 비교
				for (int j = 0; j < tempShark.size(); j++) {
					if (tempShark[j].x == shark[i].x && tempShark[j].y == shark[i].y) {
						out = false;
						if (tempShark[j].size < shark[i].size) {
							tempShark[j].size = shark[i].size;
							tempShark[j].dir = shark[i].dir;
							tempShark[j].vel = shark[i].vel;
						}
						break;
					}
				}
			}
			else {
				visited[shark[i].y][shark[i].x] = 1; // 없으면 체크
			}
			if (out) tempShark.push_back(shark[i]);
		}
		shark.clear();
		shark = tempShark;

	}
	printf("%d\n", ans);
	return 0;
}