#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

int arr[5][5];

bool check() {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		int sum = 0;
		int Sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += arr[i][j];
			Sum += arr[j][i];
		}
		if (!sum) cnt++;
		if (!Sum)cnt++;
	}

	int sum = 0;
	int Sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i][i];
		Sum += arr[i][4 - i];
	}
	if (!sum)cnt++;
	if (!Sum) cnt++;

	if (cnt >= 3) return true;
	else return false;
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];

	vector<int> v(25);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) cin >> v[i * 5 + j];


	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {

			for (int a = 0; a < 5; a++) {
				for (int b = 0; b < 5; b++) {
					if(arr[a][b] == v[i * 5 + j])
						arr[a][b] = 0;
				}
			}
			if (check()) {
				cout << i * 5 + j + 1;
				return 0;
			}
		}
			


	
	return 0;
}