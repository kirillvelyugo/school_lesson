#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

void read_file(vector <int> &v){
    fstream file("27-13b.txt");
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
    queue <int> q;

    int c = 0, c2 = 0, c7 = 0, c14 = 0, count = 0;
    for (int i = 0; i < 7; i++){
        q.push(v[i]);
    }

    for (int i = 7; i < v.size(); i++){
        int x = q.front(); q.pop();
        if (x % 14 == 0){
            c14++;
        }else if (x % 7 == 0){
            c7++;
        }else if (x % 2 == 0){
            c2++;
        }else{
            c++;
        }
        q.push(v[i]);
        if (v[i] % 14 == 0){
            count += c14 + c7 + c2 + c;
        }else if(v[i] % 7 == 0){
            count += c14 + c2;
        }else if (v[i] % 2 == 0){
            count += c14 + c7;
        }else{
            count += c14;
        }
    }

    cout << count << endl;
    return 0;
}
