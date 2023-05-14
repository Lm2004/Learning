// Задача: https://acmp.ru/?id_task=187&main=task

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
    int n;
    cin >> n;
    int m = 2 * n - 1;
    vector<vector<long long>> arr(m, vector<long long>(m, 0));
    arr[0][0] = 1;

    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < m; ++y) {
            if (m >= y - x + n && y - x + n > 0) {
                if (x > 0){
                    arr[y][x] += arr[y][x - 1];
                }
                if (y > 0){
                    arr[y][x] += arr[y - 1][x];
                }
                if (x > 0 && y > 0){
                    arr[y][x] += arr[y - 1][x - 1];
                }
            }
        }
    }

    cout << arr[m - 1][m - 1] << endl;

    return 0;
}
