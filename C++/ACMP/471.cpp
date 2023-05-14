// Задача: https://acmp.ru/index.asp?main=task&id_task=471

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

int main() {
    int N;
    size_t res = 0;
    cin >> N;

    vector<vector<int>> vect(10, vector<int>(21, 0));

    if (N == 1) {
        cout << 8 << endl;
        return 0;
    } else if (N == 2) {
        cout << 16 << endl;
        return 0;
    }

    for (int d = 0; d <= 9; d++) {
      	vect[d][0] = 1;
      	vect[d][1] = 1;
    }

    vect[0][1] = 0;
    vect[8][1] = 0;

    for (int k = 2; k <= N; k++) {
        vect[0][k] = vect[4][k - 1] + vect[6][k - 1];
        vect[1][k] = vect[6][k - 1] + vect[8][k - 1];
        vect[2][k] = vect[7][k - 1] + vect[9][k - 1];
        vect[3][k] = vect[4][k - 1] + vect[8][k - 1];
        vect[4][k] = vect[0][k - 1] + vect[3][k - 1] + vect[9][k - 1];
        vect[6][k] = vect[0][k - 1] + vect[1][k - 1] + vect[7][k - 1];
        vect[7][k] = vect[2][k - 1] + vect[6][k - 1];
        vect[8][k] = vect[1][k - 1] + vect[3][k - 1];
        vect[9][k] = vect[2][k - 1] + vect[4][k - 1];
    }
    for (int d = 0; d <= 9; d++) {
        res += vect[d][N];
    }

    cout << res << endl;
    return 0;
}