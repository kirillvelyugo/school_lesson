#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    map <int, int> d;
    for (int m = 1; m <= 1000; m += 2){
        for (int n = 2; n <= 1000; n += 2){
            int p = pow(2, m) * pow(3, n);
            if (p >= 150000000 && p <= 300000000){
                d[p] = m + n;
            }
        }
    }

    for (auto i = d.begin(); i != d.end(); i++){
        cout << i -> first << ' ' << i -> second << endl;
    }
    return 0;
}



