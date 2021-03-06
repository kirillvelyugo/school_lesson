#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    vector <int> v(4, INT_MIN);
    fstream file("27-10b.txt");
    int count, n_1, n_2, n_3;
    file >> count >> n_1 >> n_2 >> n_3;

    v[n_1 % 4] = n_1;
    v[n_2 % 4] = max(v[n_2 % 4], n_2);
    v[n_3 % 4] = max(v[n_3 % 4], n_3);

    for (int i = 1; i < count; i++){
        vector <int> tmp(4, INT_MIN);
        file >> n_1 >> n_2 >> n_3;
        for (int j = 0; j < 4; j++){
            if (v[j] == INT_MIN){
                continue;
            }
            int s_1 = v[j] + n_1, s_2 = v[j] + n_2, s_3 = v[j] + n_3;
            int p_1 = s_1 % 4, p_2 = s_2 % 4, p_3 = s_3 % 4;

            tmp[p_1] = max(tmp[p_1], s_1);
            tmp[p_2] = max(tmp[p_2], s_2);
            tmp[p_3] = max(tmp[p_3], s_3);
        }
        v = tmp;
    }

    cout << *max_element(v.begin() + 1, v.end());

    return 0;
}
// ?????:
