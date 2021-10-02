#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> a (1000, -1000);

int game (int x){
    if (a[x] != -1000){
        return a[x];
    }
    if (x == 1){
        return a[x] = 0;
    }

    int res = 0;
    vector <int> tmp = {
        x % 2 == 0 ? game(x / 2) : game(x - 2),
        x % 3 == 0 ? game(x / 3) : game(x - 3)
    };
    vector <int> neg;

    for (int i = 0; i <= tmp.size(); i++){
        if (tmp[i] <= 0){
            neg.push_back(tmp[i]);
        }
    }

    if(!neg.empty()){
        res = *max_element(neg.begin(), neg.end());
        res = -res + 1;
    }else {
        res = -*max_element(tmp.begin(), tmp.end());
    }

    return a[x] = res;
}

int main()
{
    for (int i = 2; i <= 37; i++){
        int r = game(i);
        if (r == -1){
            cout << '(' << i << ") " << r << endl;
        }
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
// 19 - 4
// 20 - 7 18
// 21 - 9
