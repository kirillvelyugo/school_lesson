#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

bool checkPrime (int n){
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void find_divs(int n, vector <int> &divs){
    for (int i = 2; i * i <= n; i++){
        if (i * i == n){
            if (checkPrime(i)){
                divs.push_back(i);
            }
        }else if (n % i == 0){
            if (checkPrime(i)){
                divs.push_back(i);
            }
            if (checkPrime(n / i)){
                divs.push_back(n / i);
            }
        }
    }
}

int main()
{
    int count = 0, min_num = INT_MAX;
    for (int i = 158928; i <= 345293; i++){
        vector <int> divs;
        find_divs(i, divs);

        if (divs.size() >= 3){
            for (int x = 0; x < divs.size(); x++){
                for (int j = x + 1; j < divs.size(); j++){
                    for (int v = j + 1; v < divs.size(); v++){
                        int mul = divs[x] * divs[j] * divs[v];
                        if (mul == i){
                            count++;
                            min_num = min(min_num, mul);
                        }
                    }
                }
            }
        }


    }

    cout << count << ' ' << min_num;
    return 0;
}
