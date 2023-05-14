// Задача: https://codeforces.com/problemset/problem/770/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <map>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> used;
vector<int> answer;
bool cycle = false;


void dfs(int node) {
    if (used[node] == 0) {
        used[node] = 1;

        for (auto to: graph[node]) {
                dfs(to);
        }

        answer.push_back(node);
        used[node] = 2;
    } else if (used[node] == 1){
        cycle = true;
    }
}

int main() {
    int n, k;

    cin >> n >> k;

    graph.resize(n + 1, vector<int>());
    used.resize(n + 1, 0);
    vector<int> important;

    for (int i = 0; i < k; ++i) {
        int y;
        cin >> y;
        important.push_back(y);
    }

    for (int i = 1; i < n + 1; ++i) {
        int m, x;
        cin >> m;

        for (int j = 0; j < m; ++j) {
            cin >> x;
            graph[i].push_back(x);
        }
    }

    for (auto node: important) {
        if (used[node] == 0){
            dfs(node);
        }
    }

    if (cycle)
        cout << -1;
    else {
        cout << answer.size() << endl;
        for (auto x: answer){
            cout << x << " ";
        }
    }
}