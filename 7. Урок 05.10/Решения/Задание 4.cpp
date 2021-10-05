#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    fstream file("27-4b.txt");
    int count, n_1, n_2;
    file >> count >> n_1 >> n_2;
    vector <int> v(5, INT_MIN);

    v[n_1 % 5] = n_1;
    v[n_2 % 5] = max(v[n_2 % 5], n_2);

    for (int i = 1; i < count; i++){
        vector <int> tmp(5, INT_MIN);
        file >> n_1 >> n_2;

        for (int j = 0; j < 5; j++){
            if (v[j] == INT_MIN){
                continue;
            }
            int s_1 = v[j] + n_1, s_2 = v[j] + n_2;
            int p_1 = s_1 % 5, p_2 = s_2 % 5;

            tmp[p_1] = max(tmp[p_1], s_1);
            tmp[p_2] = max(tmp[p_2], s_2);
        }
        v = tmp;
    }
    cout << v[0] << endl;
    return 0;
}
