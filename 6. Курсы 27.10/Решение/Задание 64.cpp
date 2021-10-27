// Напишите программу, которая ищет среди целых чисел, принадлежащих 
// числовому отрезку [2532000; 2532160], простые числа. 
// Найдите все простые числа, которые заканчиваются на цифру 7. 
// Выведите их в порядке возрастания, слева от каждого числа выведите 
// его номер по порядку.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool checkPrime (int n){
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main (){
    vector <int> v;
    for (int i = 2532000; i <= 2532160; i++){
        if (checkPrime(i) && i % 10 == 7){
            v.push_back(i);
        }    
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= v.size(); i++){
        cout << i << ' ' << v[i - 1] << endl;
    }
}