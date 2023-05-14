// Задача: https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=21&id_topic=51&id_problem=665

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
    int x1, y1, x2, y2;
    queue <pair<int, int>> que;
    string str;

    cin >> str;    
    x1 = str[0] - 'a';
    y1 = str[1] - '1';

    cin >> str;
    x2 = str[0] - 'a';
    y2 = str[1] - '1';

    vector <vector <int>>  vect1(8, vector <int>(8, 1000000));
    vector <vector <int>>  vect2(8, vector <int>(8, 1000000));
    vect1[x1][y1] = 0;
    que.push(make_pair(x1, y1));
    while(!que.empty()){
        pair <int, int> b;

        b = que.front();
        que.pop();

        if(b.first < 6 and b.second < 7 and vect1[b.first + 2][b.second + 1] == 1000000){
            vect1[b.first + 2][b.second + 1] = vect1[b.first][b.second] + 1;
            que.push(make_pair(b.first + 2, b.second + 1));
        }

        if(b.first < 7 and b.second < 6 and vect1[b.first + 1][b.second + 2] == 1000000){
            vect1[b.first + 1][b.second + 2] = vect1[b.first][b.second] + 1;
            que.push(make_pair(b.first + 1, b.second + 2));
        }

        if(b.first < 6 and b.second > 0 and vect1[b.first + 2][b.second - 1] == 1000000){
            vect1[b.first + 2][b.second - 1] = vect1[b.first][b.second] + 1;
            que.push(make_pair(b.first + 2, b.second - 1));
        }

        if(b.first > 0 and b.second < 6 and vect1[b.first - 1][b.second + 2] == 1000000){
            vect1[b.first - 1][b.second + 2] = vect1[b.first][b.second] + 1;
            que.push(make_pair(b.first - 1, b.second + 2));
        }

        if(b.first > 1 and b.second < 7 and vect1[b.first - 2][b.second + 1] == 1000000){
            vect1[b.first - 2][b.second + 1] = vect1[b.first][b.second] + 1;
            que.push(make_pair(b.first - 2, b.second + 1));
        }

        if(b.first < 7 and b.second > 1 and vect1[b.first + 1][b.second - 2] == 1000000){
            vect1[b.first + 1][b.second - 2] = vect1[b.first][b.second] + 1;
            que.push(make_pair(b.first + 1, b.second - 2));
        }

        if(b.first > 0 and b.second > 1 and vect1[b.first - 1][b.second - 2] == 1000000){
            vect1[b.first - 1][b.second - 2] = vect1[b.first][b.second] + 1;
            que.push(make_pair(b.first - 1, b.second - 2));
        }

        if(b.first > 1 and b.second > 0 and vect1[b.first - 2][b.second - 1] == 1000000){
            vect1[b.first - 2][b.second - 1] = vect1[b.first][b.second] + 1;
            que.push(make_pair(b.first - 2, b.second - 1));
        }
    }

    vect2[x2][y2] = 0;
    que.push(make_pair(x2, y2));

    while(!que.empty()){
        pair <int, int> b;

        b = que.front();
        que.pop();

        if(vect1[b.first][b.second] == vect2[b.first][b.second]){
            cout << vect1[b.first][b.second];
            return 0;
        }
        if(b.first < 6 and b.second < 7 and vect2[b.first + 2][b.second + 1] == 1000000){
            vect2[b.first + 2][b.second + 1] = vect2[b.first][b.second] + 1;
            que.push(make_pair(b.first + 2, b.second + 1));
        }
        if(b.first < 7 and b.second < 6 and vect2[b.first + 1][b.second + 2] == 1000000){
            vect2[b.first + 1][b.second + 2] = vect2[b.first][b.second] + 1;
            que.push(make_pair(b.first + 1, b.second + 2));
        }
        if(b.first < 6 and b.second > 0 and vect2[b.first + 2][b.second - 1] == 1000000){
            vect2[b.first + 2][b.second - 1] = vect2[b.first][b.second] + 1;
            que.push(make_pair(b.first + 2, b.second - 1));
        }
        if(b.first > 0 and b.second < 6 and vect2[b.first - 1][b.second + 2] == 1000000){
            vect2[b.first - 1][b.second + 2] = vect2[b.first][b.second] + 1;
            que.push(make_pair(b.first - 1, b.second + 2));
        }
        if(b.first > 1 and b.second < 7 and vect2[b.first - 2][b.second + 1] == 1000000){
            vect2[b.first - 2][b.second + 1] = vect2[b.first][b.second] + 1;
            que.push(make_pair(b.first - 2, b.second + 1));
        }
        if(b.first < 7 and b.second > 1 and vect2[b.first + 1][b.second - 2] == 1000000){
            vect2[b.first + 1][b.second - 2] = vect2[b.first][b.second] + 1;
            que.push(make_pair(b.first + 1, b.second - 2));
        }
        if(b.first > 0 and b.second > 1 and vect2[b.first - 1][b.second - 2] == 1000000){
            vect2[b.first - 1][b.second - 2] = vect2[b.first][b.second] + 1;
            que.push(make_pair(b.first - 1, b.second - 2));
        }
        if(b.first > 1 and b.second > 0 and vect2[b.first - 2][b.second - 1] == 1000000){
            vect2[b.first - 2][b.second - 1] = vect2[b.first][b.second] + 1;
            que.push(make_pair(b.first - 2, b.second - 1));
        }
    }
    cout << -1;
    return 0;
}