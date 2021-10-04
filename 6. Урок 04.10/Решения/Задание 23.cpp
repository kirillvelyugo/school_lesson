#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    vector <int> v(10, INT_MIN);
    int count, n_1, n_2;
    fstream file("27-23b.txt");
    file >> count >> n_1 >> n_2;

    v[n_1 % 10] = n_1;
    v[n_2 % 10] = max(v[n_2 % 10], n_2);

    for (int i = 1; i < count; i++) {
        vector <int> tmp(10, INT_MIN);
        file >> n_1 >> n_2;
        
        for (int j = 0; j < 10; j++) {
            if (v[j] == INT_MIN) {
                continue;
            }
            int s_1 = v[j] + n_1, s_2 = v[j] + n_2;
            int p_1 = s_1 % 10, p_2 = s_2 % 10;

            tmp[p_1] = max(tmp[p_1], s_1);
            tmp[p_2] = max(tmp[p_2], s_2);
        }
        v = tmp;
    }

    v[5] = INT_MIN;
    cout << *max_element(v.begin(), v.end()) << endl;

    return 0;
}


// Ответ - 13159 40799380