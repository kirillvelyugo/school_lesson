#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    fstream file("C:\\Users\\302-7\\Desktop\\ege\\data\\17\\27-17b.txt");
    int n, x;
    file >> n;

    queue <int> q;
    for (int i = 0; i < 5; i++){
        file >> x;
        q.push(x);
    }

    int count = 0, c_c = 0, c13_c = 0, c_n = 0, c13_n = 0;
    for (int i = 5; i < n; i++){
        file >> x;
        int a = q.front();
        q.push(x);
        q.pop();
        if (a % 13 == 0 && a % 2 == 0){
            c13_c++;
        }else if (a % 13 == 0 && a % 2 != 0){
            c13_n++;
        }else if (a % 13 != 0 && a % 2 == 0){
            c_c++;
        }else if (a % 13 != 0 && a % 2 != 0){
            c_n++;
        }

        if (x % 13 == 0 && x % 2 == 0){
            count += c_n + c13_n;
        }else if (x % 13 == 0 && x % 2 != 0){
            count += c_c + c13_c;
        }else if (x % 13 != 0 && x % 2 == 0){
            count += c13_n;
        }else if (x % 13 != 0 && x % 2 != 0){
            count += c13_c;
        }
    }
    cout << count << endl;
    return 0;
}
