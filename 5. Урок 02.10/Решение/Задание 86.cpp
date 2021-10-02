#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector<int>> a(1000, vector<int>(1000, -1000));

int game (int x, int y){
    if (a[x][y] != -1000){
        return a[x][y];
    }
    if (x + y >= 45){
        return a[x][y] = 0;
    }

    int res = 0;
    vector <int> tmp = {game(x, x + y), game(x + y, y)};
    vector <int> neg;

    for (int i = 0; i < tmp.size(); i++){
        if (tmp[i] <= 0){
            neg.push_back(tmp[i]);
        }
    }

    if (!neg.empty()){
        res = *max_element(neg.begin(), neg.end());
        res = -res + 1;
    }else {
        res = -*max_element(tmp.begin(), tmp.end());
    }

    return a[x][y] = res;
}

int main()
{
    for (int i = 1; i <= 45; i++){
        int r = game(7, i);
        if (r == 1){
            cout << '(' << 7 << ',' << i << ") " << r << endl;
        }
    }
    return 0;
}

// Ответ:
// 19 - 11
// 20 - 7 13
// 21 - 4
