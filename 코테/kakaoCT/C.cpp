#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<vector<vector<vector<int>>>>> arr(3, vector <vector<vector<vector<int>>>>(2, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>()))));
map<pair<string, int>, int> m;

int dfs(vector<string>& v, int depth, string order) {
    if (depth == 4) {
        int x = order[0] - '0';
        int y = order[1] - '0';
        int w = order[2] - '0';
        int z = order[3] - '0';

        int cnt = arr[x][y][w][z].end() - lower_bound(arr[x][y][w][z].begin(), arr[x][y][w][z].end(), stoi(v[depth]));
        return cnt;
    }

    int ret = 0;

    if (v[depth] == "-") {
        ret += dfs(v, depth + 1, order + "0");
        ret += dfs(v, depth + 1, order + "1");
        if (depth == 0) ret += dfs(v, depth + 1, order + "2");
    }
    else {
        ret += dfs(v, depth + 1, order + to_string(m[{ v[depth], depth }]));
    }

    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    m[{"cpp", 0}] = 0;
    m[{"java", 0}] = 1;
    m[{"python", 0}] = 2;
    m[{"backend", 1}] = 0;
    m[{"frontend", 1}] = 1;
    m[{"junior", 2}] = 0;
    m[{"senior", 2}] = 1;
    m[{"chicken", 3}] = 0;
    m[{"pizza", 3}] = 1;

    for (int i = 0; i < info.size(); i++) {
        stringstream ss(info[i]);
        string temp;
        int index[4];
        int idx = 0;
        while (ss >> temp) {
            switch (idx) {
            case 0:
                if (temp[0] == 'c') index[0] = 0;
                else if (temp[0] == 'j') index[0] = 1;
                else index[idx] = 2;
                break;
            case 1:
                if (temp[0] == 'b') index[1] = 0;
                else index[idx] = 1;
                break;
            case 2:
                if (temp[0] == 'j') index[2] = 0;
                else index[idx] = 1;
                break;
            case 3:
                if (temp[0] == 'c') index[3] = 0;
                else index[idx] = 1;
                break;
            }
            idx++;
        }
        arr[index[0]][index[1]][index[2]][index[3]].push_back(stoi(temp));
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++) sort(arr[i][j][k][l].begin(), arr[i][j][k][l].end());

    for (int i = 0; i < query.size(); i++) {
        stringstream ss(query[i]);
        vector<string> temp;
        string x;
        while (ss >> x) {
            if (x != "and") temp.push_back(x);
        }
        answer.push_back(dfs(temp, 0, ""));
    }
    return answer;
}

void solve() {
    solution({ "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" }, { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" });
}

int main() {
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}