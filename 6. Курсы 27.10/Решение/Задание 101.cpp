/******************************************************************************
Среди целых чисел, принадлежащих числовому отрезку [125697;190234], 
найдите числа, которые представляют собой произведение двух различных простых 
делителей. Запишите в ответе количество таких чисел и максимальное их них.
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

bool f (int n){
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
    if (v.size() == 2){
        return v[0] * v[1] == n;
    }else{
        return false;
    }
}

int main()
{
    int count = 0, max = INT_MIN;
    for (int i = 125697; i<= 190234; i++){
        if (f(i)){
            count++;
            if (i > max){
                max = i;
            }
        }
    }
    cout << count << ' ' << max << endl;
    return 0;
}
