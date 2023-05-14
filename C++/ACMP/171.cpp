// Задача: https://acmp.ru/index.asp?main=task&id_task=171
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
    size_t N, result = 1, divisior = 2;
    cin >> N;

    while (N > 1){
        size_t count = 0;
        while (N % divisior == 0){
            count++;
            N = N / divisior;
        }
        result *= (count + 1);
        count = 0;
        if (divisior == 2){
            divisior++;
        } else{
            divisior += 2;
        }
    }

    cout << result << endl;
}