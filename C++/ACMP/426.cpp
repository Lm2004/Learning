// Задача: https://acmp.ru/index.asp?main=task&id_task=426

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
    cin >> N;

    int d[N][N], p[N][N], x[4] = {-1,1,0,0}, y[4] = {0,0,-1,1}, x1, y1, x2, y2;
    queue<pair<int,int>> que;
    string a[N];
    
    for(int i = 0; i < N; i++){
        cin >> a[i];

        for(int j = 0; j < N; j++){
            d[i][j] = MAX_int;

            if(a[i][j] == '@'){
                x1 = i;
                y1 = j;
            }else if(a[i][j] == 'X'){
                x2 = i;
                y2 = j;
            }
        }
    }

    int i, j, u, v, k;
    d[x1][y1] = 0;
    que.push(make_pair(x1,y1));

    while(!que.empty()){
        i = que.front().first;
        j = que.front().second;
        que.pop();

        for(int k = 0; k < 4; k++){
            u = i + x[k];
            v = j + y[k];

            if(u >= 0 and u < N and v >= 0 and v < N and a[u][v] != 'O' and d[u][v] > d[i][j] + 1){
                d[u][v] = d[i][j] + 1;
                p[u][v] = k;
                que.push(make_pair(u,v));
            }

        }
    }
    if(d[x2][y2] < MAX_int){
        cout << 'Y' << endl;
        i = x2;
        j = y2;

        while(a[i][j] != '@'){
            a[i][j] = '+';
            k = p[i][j];
            i = i - x[k];
            j = j - y[k];
        }

        for(int t = 0; t < N; t++){
            cout << a[t] << endl;
        }

        return 0;
    }

    cout << 'N';

    return 0;
}