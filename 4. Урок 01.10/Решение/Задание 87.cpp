#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<vector<int>>> a(100, vector<vector<int>>(100, vector<int>(100, -1000)));

int game(int x, int y, int z){
    if (a[x][y][z] != -1000){
        return a[x][y][z];
    }
    if (x + y + z >= 73){
        return a[x][y][z] = 0;
    }

    int res = 0;
    // +3 +13 +23
    vector <int> tmp = {
        game(x + 3, y , z), game(x, y + 3, z), game(x, y , z + 3),
        game(x + 13, y , z), game(x, y + 13, z), game(x, y, z + 13),
        game(x + 23, y, z), game(x, y + 23, z), game(x, y, z + 23)
    };
    vector <int> neg;

    for (int i = 0; i < tmp.size(); i++){
        if (tmp[i] <= 0){
            neg.push_back(tmp[i]);
        }
    }

    if (!neg.empty()){
        res = *max_element(neg.begin(), neg.end());
        res = - res + 1;
    }else{
        res = -*max_element(tmp.begin(), tmp.end());
    }

    return a[x][y][z] = res;
}

int main()
{
    for (int s = 1; s <= 23; s++){
        int res = game(2, s, 2 * s);
        if (res == 1){
            cout << '(' << 2 << ',' << s << ',' << 2 * s << ") " << res << endl;
        }
        if (res == 2){
            cout << '(' << 2 << ',' << s << ',' << 2 * s << ") " << res << endl;
        }
        if (res == -2){
            cout << '(' << 2 << ',' << s << ',' << 2 * s << ") " << res << endl;
        }
    }
    return 0;
}
