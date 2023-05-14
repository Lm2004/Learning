// Задача: https://codeforces.com/problemset/problem/217/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <cmath>

using namespace std;

bool boo[1000] = {0};
long long N, arr[1000][1000];

void Run(long long i)
{
    boo[i] = 1;
    for(long long j = 1; j <= N; j++){
        if(!boo[j] and (arr[0][i]==arr[0][j] or arr[1][i]==arr[1][j]))
        Run(j);
    }
}

int main(){
    cin >> N;
    for(long long i = 1; i <= N; i++){
        cin >> arr[0][i] >> arr[1][i];
    }
    
    long long result = -1;
    for(long long i = 1; i <= N; i++){
        if(!boo[i])
        {
            Run(i);
            result++;
        }
    }
    cout << result << endl;
    return 0;
}
