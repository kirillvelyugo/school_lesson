#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    fstream file("27.2.txt");
    int count, n_1, n_2, n_3;
    file >> count >> n_1 >> n_2 >> n_3;
    vector <int> v(4, INT_MIN);
    int x = n_1 + n_2, y = n_1 + n_3, z = n_2 + n_3;

    v[x % 4] = x;
    v[y % 4] = max(v[y % 4], y);
    v[z % 4] = max(v[z % 4], z);

    for (int i = 1; i < count; i++){
        vector <int> tmp(4, INT_MIN);
        file >> n_1 >> n_2 >> n_3;

        for (int j = 0; j < 4; j++){
            if (v[j] == INT_MIN){
                continue;
            }
            int s_1 = v[j] + n_1 + n_2, s_2 = v[j] + n_1 + n_3, s_3 = v[j] + n_2 + n_3;
            int p_1 = s_1 % 4, p_2 = s_2 % 4, p_3 = s_3 % 4;

            tmp[p_1] = max(tmp[p_1], s_1);
            tmp[p_2] = max(tmp[p_2], s_2);
            tmp[p_3] = max(tmp[p_3], s_3);
        }
        v = tmp;
    }
    cout << v[0] << endl;
    return 0;
}
