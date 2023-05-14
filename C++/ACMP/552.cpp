// Задача: https://acmp.ru/index.asp?main=task&id_task=552

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

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    vector<vector<long long>> vect(4, vector<long long>(N + 1, 1));
    for(int i = 1; i <= 3; i++){
        vect[i][N] = 0;
        for(int j = N - 1; j >= 0; j--){
            vect[i][j] = vect[i][j + 1] + vect[i - 1][j + 1] * arr[j];
        }
    }
    cout << vect[3][0] << endl;
    return 0;
}