// Cреди целых чисел, принадлежащих числовому отрезку [87921; 88187], 
// найдите числа, сумма цифр которых кратна 14, а произведение цифр кратно 18
// и не равно 0. Для каждого найденного числа запишите сумму и произведение его
// цифр в таблицу на экране с новой строки в порядке возрастания произведения цифр.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int sumDig (int n){
    int sum = 0;
    while (n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int mulDig (int n){
    int mul = 1;
    while (n){
        mul *= n % 10;
        n /= 10;
    }
    return mul;
}

int main (){
    map <int, int> m;
    for (int i = 87921; i <= 88187; i++){
        if (sumDig(i) % 14 == 0 && mulDig(i) % 18 == 0 && mulDig(i) != 0){
            m[mulDig(i)] = sumDig(i);
        }
    }
    for (auto i = m.begin(); i != m.end(); i++){
        cout << i->second << ' ' << i->first << endl;
    }
}