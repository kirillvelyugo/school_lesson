#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    vector <int> v(10, INT_MAX);
    int n, x, y;
    fstream file("27-22b.txt");
    file >> n >> x >> y;
    v[x % 10] = x;
    v[y % 10] = min(v[y % 10], y);
    for (int i = 1; i < n; i++){
        vector <int> tmp (10, INT_MAX);
        file >> x >> y;
        for (int j = 0; j < 10; j++){
            if (v[j] == INT_MAX){
                continue;
            }
            int s1 = v[j] + x, s2 = v[j] + y;
            int p1 = s1 % 10, p2 = s2 % 10;
            tmp[p1] = min(tmp[p1], s1);
            tmp[p2] = min(tmp[p2], s2);
        }
        v = tmp;
    }
    cout << v[4] << endl ;

    return 0;
}
