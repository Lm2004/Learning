// Задача: https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=32&id_topic=52&id_problem=1025

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

int n;
bool ok = false;
vector<vector<int>> arr;
vector<int> used;

void dfs(int node) {
    if (used[node] == 0) {
        used[node] = 1;
        for (int i = 1; i < n + 1; i++) {
            if (arr[node][i]){
                dfs(i);
            }
        }
        used[node] = 2;
    } else if (used[node] == 1){
        ok = true;
        return;
    }
}

int main(){
    cin >> n;
    arr.assign(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            cin >> arr[i][j];
        }
    }

    used.assign(n+1, 0);
    for (int i = 1; i < n + 1; i++){
        if (!used[i]){
            dfs(i);
        }
    }
    cout << ok;
    return 0;
}