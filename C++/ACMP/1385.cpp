// Задача: https://acmp.ru/asp/do/index.asp?main=topic&id_course=2&id_section=32&id_topic=55

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int arr[M][3], cost[N + 1];
    
    for(int i = 0; i < M; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for(int i = 1; i <= N; i++){
        cost[i] = i;
    }

    int temp, cost0, cost1, d, p=0;

    for(int i = 0; i < N - 1; i++){
        d = 30001;
        for(int j = 0; j < M; j++){
            if(cost[arr[j][0]] != cost[arr[j][1]] and arr[j][2] < d){
                d = arr[j][2];
                temp = j;
            }
        }
        p += d;
        cost0 = cost[arr[temp][0]];
        cost1 = cost[arr[temp][1]];
        for(int j = 1; j <= N; j++){
            if(cost[j] == cost1){
                cost[j] = cost0;
            }
        }
    }
    cout << p;
    return 0;
}