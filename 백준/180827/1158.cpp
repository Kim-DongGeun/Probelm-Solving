#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> arr;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		arr.push(i);

	cout << "<";
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M - 1; j++){
			arr.push(arr.front());
			arr.pop();
		}
		cout << arr.front() << ", ";
		arr.pop();
	}
	cout << arr.front() << ">\n";

	return 0;
}