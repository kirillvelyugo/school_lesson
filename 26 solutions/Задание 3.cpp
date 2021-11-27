#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    fstream file("C:\\Users\\302-5\\Desktop\\26s\\tasks\\26-k2.txt");
    vector <int> mes;
    int n, k;
    file >> n >> k;

    int x;
    while (file >> x){
        mes.push_back(x);
    }

    sort(mes.begin(), mes.end());
    mes.erase(mes.begin(), mes.begin() + k);
    reverse(mes.begin(), mes.end());
    mes.erase(mes.begin(), mes.begin() + k);

    int num = *max_element(mes.begin(), mes.end());

    int average = 0;
    for (auto x: mes){
        average += x;
    }
    average /= mes.size();

    cout << num << ' ' << average << endl;
    return 0;
}
