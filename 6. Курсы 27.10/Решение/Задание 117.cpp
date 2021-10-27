/******************************************************************************
Рассматриваются целые числа, принадлежащих числовому отрезку [105673; 220784], 
которые представляют собой произведение трёх различных простых делителей. 
В ответе запишите количество таких чисел и максимальное из них.
*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

bool checkPrime (int n){
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

bool check (int n){
    vector <int> v;
    for (int i = 2; i * i <= n; i++){
        if (i * i == n){
            if (checkPrime(i)){
                v.push_back(i);
            }
        }else if (n % i == 0){
            if (checkPrime(i)){
                v.push_back(i);
            }
            if (checkPrime(n / i)){
                v.push_back(n / i);
            }
        }
    }
    if (v.size() == 3){
        return v[0] * v[1] * v[2] == n;
    }else{
        return false;
    }
}

int main()
{
    int count = 0, max = INT_MIN;
    for (int i = 105673; i <= 220784; i++){
        if (check(i)){
            count++;
            if (i > max){
                max = i;
            }
        }
    }
    
    cout << count << ' ' << max << endl;
    return 0;
}
