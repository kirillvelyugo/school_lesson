#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <fstream>
#include <climits>
using namespace std;

int main()
{
    fstream file("26.txt");
    vector <int> v;
    int s, n, count = 0;
    file >> s >> n;

    int x;
    while (file >> x){
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int tmp_size = 0, i = 0;
    while (tmp_size + v[i] <= s){
        tmp_size += v[i];
        count++;
        i++;
    }

    tmp_size -= v[i - 1];

    while (tmp_size + v[i] <= s){
        i++;
    }


    cout << count << ' ' << v[i - 1] << endl;


    return 0;
}



