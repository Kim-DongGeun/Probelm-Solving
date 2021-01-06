//16235
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


struct pos { int x; int y; int age; 
bool operator<(pos a) const  {
    return age < a.age;
    }
};


int n, m, t, h, k;
const int INF = 1e9;

const int dx[8] = { 1, 1,0,-1, -1, -1,0, 1 };
const int dy[8] = { 0,-1, -1, -1,0,1,1,1 };

vector<int> q[12][12];
int arr[11][11];
int add[11][11];

void Input() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> add[i][j];
            arr[i][j] = 5;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, age;
        cin >> y >> x >> age;
        q[y][x].push_back(age);
    }
}
void solve() {
    while (k--) {
        //��
		vector<pos> grow; // ������ ����
		vector<pos> dead; // ���� ����
        for (int I = 1; I <= n; I++) {
            for (int J = 1; J <= n; J++) {
                if (q[I][J].size() == 0) continue;

                vector<int> tmp;
                sort(q[I][J].begin(), q[I][J].end());
                for (int i = 0; i < q[I][J].size(); i++) {
                    int age = q[I][J][i];

                    if (arr[I][J] < age) {// ���̺��� ����� ������ ����
                        dead.push_back({J, I, age / 2}); // ���� ���� �߰�
                    }
                    else {
                        arr[I][J] -= age; // ��� ����
                        age++; // ���� 1 ����
                        tmp.push_back(age);
				        if(age % 5 == 0) // ������ ���� �߰�
					        grow.push_back({ J, I, age });
                    }
                }
                q[I][J] = tmp;
            }
        }
		//����
        for (int i = 0; i < dead.size(); i++) {
            int y = dead[i].y;
            int x = dead[i].x;
            int age = dead[i].age;
			arr[y][x] += age; // ���������� ���� /2 ��ŭ ��� �߰�
		}


        //����
        int size = grow.size();
        for (int i = 0; i < size; i++) { // ����
            for (int j = 0; j < 8; j++) {
                int nx = dx[j] + grow[i].x;
                int ny = dy[j] + grow[i].y;

                if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
                else {
                    q[ny][nx].push_back(1);
                }
            }
        }
        
        //�ܿ�
        for (int i = 1; i <= n; i++) // ��� �߰�
            for (int j = 1; j <= n; j++) arr[i][j] += add[i][j];

    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)ans += q[i][j].size();

    cout << ans;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    Input();
    solve();
    return 0;
}
