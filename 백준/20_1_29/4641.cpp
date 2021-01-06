#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int main() {
    int input;
    while (true) {
        cin >> input;
        if (input == -1) break;
        arr.clear();
        arr.push_back(input);
        while (true) {
            cin >> input;
            if (input == 0) break;
            arr.push_back(input);
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (find(arr.begin(), arr.end(), arr[i] * 2) != arr.end()) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}