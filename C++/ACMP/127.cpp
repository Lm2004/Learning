// Задача: https://acmp.ru/index.asp?main=task&id_task=127

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include<queue>

#define MAX_int 1000000000

using namespace std;

int main() {
    int N;
    queue<int> q;

    cin >> N;

    int a[N][N], d[N];
    for(int t = 0; t < N; t++){
        d[t] = MAX_int;

        for(int j = 0;j < N; j++){
            cin >> a[t][j];
        }

    }
    int s, f, i;

    cin >> s >> f;

    s = s - 1;
    f = f - 1;

    d[s]=0;
    q.push(s);

    while(!q.empty()){

        i = q.front();
        q.pop();

        for(int j = 0; j < N; j++){
            if(a[i][j] and d[j] > d[i] + 1){
                d[j] = d[i] + 1;
                q.push(j);
            }
        }

    }
    if(d[f] < MAX_int){
        cout << d[f];
        return 0;
    }
    cout << -1;
    return 0;
}