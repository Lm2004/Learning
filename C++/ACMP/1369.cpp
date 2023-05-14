// Задача: https://contest.nlogn.info/contest/3285/problems/A

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
    int N;
    cin >> N;
    int a[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){ 
            cin >> a[i][j];
            if(a[i][j] < 0){
                a[i][j] = MAX_int;
            }
        }
    }
    for(int t = 0; t < N; t++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(a[i][j] > a[i][t] + a[t][j]){
                    a[i][j] = a[i][t] + a[t][j];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] < MAX_int and a[i][j] > ans){
                ans = a[i][j];
            }
        }
    }
    cout << ans;
    return 0;
}