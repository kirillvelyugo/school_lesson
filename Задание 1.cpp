#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <fstream>
using namespace std;

int main()
{
    fstream file("C:\\Users\\302-7\\Desktop\\cpp\\data\\27-1a.txt");
    int n, a, b;
    file >> n >> a >> b;

    vector <int> v(3, INT_MAX);
    v[a % 3] = a;
    v[b % 3] = min(b, v[b % 3]);

    while (file >> a >> b){
        vector <int> tmp(3, INT_MAX);

        for (int i = 0; i < 3; i++){
            if (v[i] == INT_MAX){
                continue;
            }

            int s_1 = v[i] + a, s_2 = v[i] + b;
            int p_1 = s_1 % 3, p_2 = s_2 % 3;

            tmp[p_1] = min(tmp[p_1], s_1);
            tmp[p_2] = min(tmp[p_2], s_2);
        }
        v = tmp;
    }
    cout << min(v[1], v[2]);

    return 0;
}

