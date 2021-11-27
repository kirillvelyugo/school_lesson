#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <fstream>
#include <climits>
using namespace std;

bool checkNum (int n){
    while (n){
        if ((n % 10) % 2 != 0){
            return false;
        }
        n /= 10;
    }
    return true;
}

int main()
{
    fstream file("24.txt");
    int max_num = INT_MIN, tmp_num = 0;
    string tmp_num_str = "";
    string s;
    file >> s;

    for (int i = 0; i < s.size(); i ++){
        if (s[i] >= '0' && s[i] <= '9'){
            tmp_num_str += s[i];
        }else{
            tmp_num = atoi(tmp_num_str.c_str());
            if (checkNum(tmp_num)){
                max_num = max(max_num, tmp_num);
            }
            tmp_num_str = "";
        }
    }

    cout << max_num << endl;

    return 0;
}



