#include <iostream>
#include <vector>
using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

struct robot { int x, y, dir; };
struct order { int num; char order; int repeat; };

int main() {
	int N, M, A, B;
	int x, y; char dir;
	vector<robot> robotLoc;
	vector<order> orderList;

	cin >> A >> B;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> x >> y >> dir;
		switch (dir)
		{
		case 'E':
			robotLoc.push_back({ x - 1,B - y,0 });
			break;
		case 'S':
			robotLoc.push_back({ x - 1,B - y,1 });
			break;					   
		case 'W':					   
			robotLoc.push_back({ x - 1,B - y,2 });
			break;					   
		case 'N':					   
			robotLoc.push_back({ x - 1,B - y,3 });
			break;
		default:
			break;
		}
	}
	
	for (int i = 0; i < M; i++) {
		int num, repeat; char order;
		cin >> num >> order >> repeat;
		orderList.push_back({ num, order, repeat });
	}

	for (int T = 0; T < orderList.size(); T++) {
		int repeat = orderList[T].repeat;
		while (repeat--) {
			int nx = robotLoc[orderList[T].num - 1].x + dx[robotLoc[orderList[T].num - 1].dir];
			int ny = robotLoc[orderList[T].num - 1].y + dy[robotLoc[orderList[T].num - 1].dir];

			switch (orderList[T].order) {
			case 'L':
				robotLoc[orderList[T].num - 1].dir = (robotLoc[orderList[T].num - 1].dir + 3) % 4;
				break;
			case 'R':
				robotLoc[orderList[T].num - 1].dir = (robotLoc[orderList[T].num - 1].dir + 1) % 4;
				break;
			case 'F':
				if (nx < 0 || nx >= A || ny < 0 || ny >= B) { // crash
					printf("Robot %d crashes into the wall\n", orderList[T].num);
					return 0;
				}

				for (int i = 0; i < robotLoc.size(); i++) {
					if (i == orderList[T].num - 1) continue;
					else if (nx == robotLoc[i].x && ny == robotLoc[i].y) {
						printf("Robot %d crashes into robot %d\n", orderList[T].num, i + 1);
						return 0;
					}
				}

				robotLoc[orderList[T].num - 1].x = nx;
				robotLoc[orderList[T].num - 1].y = ny;
				break;
			default:
				break;
			}
		}
	}
	printf("OK\n");
	return 0;
}

