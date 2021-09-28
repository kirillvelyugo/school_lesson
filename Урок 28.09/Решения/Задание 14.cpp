#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> a(1000, vector<int>(1000, -1000));

int game(int x, int y) {
    if (a[x][y] != -1000) {
        return a[x][y];
    }
    if (x + y >= 74){
        return a[x][y] = 0;
    }

    vector <int> tmp = { game(x + 2,y),game(x * 2,y),game(x,y + 2),game(x,y * 2) }; 
    vector<int>neg;
    int res = 0;

    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] <= 0) {
            neg.push_back(tmp[i]);
        }
    }
    
    if (!neg.empty()) {
        res = *max_element(neg.begin(), neg.end());
        res = -res + 1;
    }
    else {
        res = -*max_element(tmp.begin(), tmp.end());
    }
    return a[x][y]=res;
}

int main()
{
    int x = 7;
    for (int i = 1; i <= 66; i++) {
        int r = game(x, i);
        if (r == 1) {
            cout << '(' << x << ',' << i << ") " << r << endl;
        }
        if (r == 2) {
            cout << '(' << x << ',' << i << ") " << r << endl;
        }
        if (r == -2) {
            cout << '(' << x << ',' << i << ") " << r << endl;
        }
    }

    return 0;
}
