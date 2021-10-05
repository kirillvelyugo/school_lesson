#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{

    fstream file("27-13a.txt");
    queue <int> q;
    int count_s, count_p;
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
        //*3 if
        // перебор с y

    }

    return 0;
}
