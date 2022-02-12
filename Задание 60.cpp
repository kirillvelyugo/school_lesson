#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    fstream file("27b.txt");
    vector <int> ost(25, 0);

    int x;
    while (file >> x){
        vector <int> tmp = ost;
        for (int i = 0; i < 25; i++){
            if (ost[i] == 0) continue;
            int p = (i + x % 25) % 25;
            tmp[p] = max(ost[p], x + ost[i]);
        }
        tmp[x % 25] = max(x, tmp[x % 25]);
        ost = tmp;
    }

    cout << ost[0] << endl;
    return 0;
}

