// Задача: https://codeforces.com/problemset/problem/813/F
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

int main() {
    int n, m;
    bool ok = true;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<int> part(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i < m; i++) {
        if (part[i] == -1) {
            part[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (auto x: graph[curr]) {
                    if (part[x] == -1){
                        part[x] = !part[curr];
                        q.push(x);
                        }
                    else if (part[x] == part[curr]) {
                        ok = false;
                        break;
                    }
                }
            }
        }
    }

    ok ? cout << "Yes" : cout << "No";
}