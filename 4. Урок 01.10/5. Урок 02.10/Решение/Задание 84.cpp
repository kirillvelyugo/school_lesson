#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> a (1000, -1000);

int game (int x){
    if (a[x] != -1000){
        return a[x];
    }
    if (x >= 65){
        if (x <= 100){
            return a[x] = 0;
        }else {
            return a[x] = 100;
        }
    }

    int res = 0;
    vector <int> tmp = {game(x + 1), game(x * 3)};
    vector <int> neg;

    for (int i = 0; i < tmp.size(); i++){
        if(tmp[i] <= 0){
            neg.push_back(tmp[i]);
        }
    }

    if (!neg.empty()){
        res = *max_element(neg.begin(), neg.end());
        res = -res + 1;
    }else {
        int max = 0;
        for (int z = 0; z < tmp.size(); z++){
            if (tmp[z] < 100 && tmp[z] > max){
                max = tmp[z];
            }
        }
        res = -max;
    }
    return a[x] = res;
}

int main()
{
    for (int i = 1; i <= 64; i++){
        int r = game(i);
        if (r == 1){
            cout << '(' << i << ") " << r << endl;
        }
        if (r == 2){
            cout << '(' << i << ") " << r << endl;
        }
        if (r == -2){
            cout << '(' << i << ") " << r << endl;
        }
    }
    return 0;
}

// Ответ:
// 19 -
// 20 -
// 21 -
