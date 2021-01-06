#include <string>
#include <vector>

using namespace std;

int arr[1000001] = { 0, };

int solution(vector<vector<int>> boxes) {
    int answer = -1;

    for (int i = 0; i < boxes.size(); i++) {
        arr[boxes[i][0]]++; arr[boxes[i][1]]++;
    }

    int cnt = 0;
    for (int i = 1; i <= 1000000; i++)
        cnt += arr[i] / 2;

    answer = boxes.size() - cnt;

    return answer;
}

void solve() {
    solution({ 11,2,9,13,24 }, {9,2,13,24,11});
}

int main() {
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
