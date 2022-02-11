#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

void read_file(vector <int> &v){
    fstream file("27-14b.txt");
    int cnt;
    file >> cnt;
    int n;
    while (file >> n){
        v.push_back(n);
    }
}

int main()
{
    vector <int> v;
    read_file(v);

    int count = 0;
    int ost[12] = {0};

    for (int i = 0; i < v.size(); i++){
        int ost1 = v[i] % 12;
        int ost2 = (12 - ost1) % 12;
        count += ost[ost2];
        ost[ost1]++;
    }

    cout << count << endl;
    return 0;
}
