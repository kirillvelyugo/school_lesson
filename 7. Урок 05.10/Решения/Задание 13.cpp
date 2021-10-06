#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{

    fstream file("27-13b.txt");
    queue <int> q;
    int count_s, count_p = 0;
    int c2 = 0, c7 = 0, c14 = 0, c = 0;

    file >> count_s;


    for (int i = 0; i < 7; i++){
        int n;
        file >> n;
        q.push(n);
    }
    for (int i = 7; i < count_s; i++){
        int x = q.front();
        q.pop();

        if (x % 14 == 0){
            c14++;
        }else if (x % 7 == 0 && x % 2 != 0){
            c7++;
        }else if (x % 2 == 0){
            c2++;
        }else{
            c++;
        }

        int b;
        file >> b;
        q.push(b);

        if (b % 14 == 0){
            count_p += c + c2 + c7 + c14;
        }else if (b % 7 == 0 && b % 2 != 0){
            count_p += c2 + c14;
        }else if (b % 2 == 0){
            count_p += c7 + c14;
        }else{
            count_p += c14;
        }
    }

    cout << count_p << endl;
    return 0;
}
