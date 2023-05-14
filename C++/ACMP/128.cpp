// Задача: https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=21&id_topic=51&id_problem=664
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <queue>

#define MAX_int 1000000000

using namespace std;

int main() {
    int N, x1, y1, x2, y2;
    
    cin >> N;
    int d[N+1][N+1];
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            d[i][j] = MAX_int;
        }
    }
    
    int x[8]={-2,-2,-1,-1,1,1,2,2}, y[8]={-1,1,-2,2,-2,2,-1,1}, temp1, temp2;
    queue<pair<int,int>> que;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    d[x1][y1] = 0;
    que.push(make_pair(x1,y1));

    while(!que.empty()){
        temp1 = que.front().first;
        temp2 = que.front().second;
        que.pop();
        for(int k = 0; k < 8; k++){
            int u = temp1 + x[k];
            int v = temp2 + y[k];
            if(u > 0 and u <= N and v > 0 and v <= N and d[u][v] > d[temp1][temp2] + 1){
                d[u][v] = d[temp1][temp2]+1;
                que.push(make_pair(u,v));
            }
        }
    }

    cout << d[x2][y2];
    return 0;
}