#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    fstream file ("27b.txt");
    int N;
    file >> N;

    vector <int> v(3);
    int s1, s2, s3;
    int min_raz = INT_MAX;
    while (file >> v[0] >> v[1] >> v[2]){
        sort(v.begin(), v.end());
        s3 += v[2];
        if((v[2] - v[0]) % 2){
            min_raz = min(min_raz, v[2] - v[0]);
        }
        if((v[2] - v[1]) % 2){
            min_raz = min(min_raz, v[2] - v[1]);
        }
    }

    cout << s3 - min_raz << endl;
    return 0;
}
