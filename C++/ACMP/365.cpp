// Задача: https://acmp.ru/index.asp?main=task&id_task=365

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

vector<int> vect;

void print() {
    if (vect.size() == 1){
        return;
    }

    cout << vect[0];

    for (int i = 1; i < vect.size(); ++i) {
        cout << '+' << vect[i];
    }
    cout << endl;
}

void Run(int prev, int sum) {
    if (sum == 0) {
        print();
    }

    for (int i = prev; i <= sum; ++i) {
        vect.push_back(i);
        Run(i, sum - i);
        vect.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    Run(1, n);
    return 0;
}
