// Среди целых чисел, принадлежащих числовому отрезку [333555; 777999], 
// найдите числа, среди делителей которых есть ровно 35 двузначных чисел. 
// Для каждого найденного числа запишите в ответе само число, наименьший и 
// наибольший из его двузначных делителей. Так, например, для числа 36 учитываются 
// только делители 12 и 18.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

void findDiv (int n, vector <int> &v){
    
    for (int i = 1; i * i <= n; i++){
        if (i * i == n){
            if (i >= 10 && i <= 99){
                v.push_back(i);    
            }
        }else if (n % i == 0){
            if (i >= 10 && i <= 99){
                v.push_back(i);    
            }
            if (n % i >= 10 && n % i <= 99){
                v.push_back(n % i);
            }
        }
    }
}

int main (){

    for (int i = 333555; i <= 777999; i++){
        vector <int> v;
        findDiv(i, v);
        if (v.size() == 35){
            sort(v.begin(), v.end());
            cout << i << ' ' << v[0] << ' ' << v[v.size() - 1] << endl;   
        }
    }
    return 0;
}