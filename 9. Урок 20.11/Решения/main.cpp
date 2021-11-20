#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    fstream file("24.txt");
    int max_length = INT_MIN;

    string s;
    file >> s;

    for (int i = 0; i < s.size() - 1; i++){
        int tmp_length = 1;
        if (s[i] > s[i + 1]){
            tmp_length++;
            max_length = max(max_length, tmp_length);
        }else{
            tmp_length = 1;
        }
    }

    cout << max_length << endl;

    return 0;
}
