#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    fstream file("C:\\Users\\302-5\\Desktop\\26s\\tasks\\26-k1.txt");
    vector <int> prices;
    int n, k, sum_discount = 0, max_without = 0;
    file >> n >> k;

    int x;
    while (file >> x){
        prices.push_back(x);
    }

    sort(prices.begin(), prices.end());
    reverse(prices.begin(), prices.end());

    for (int i = 0; i <= k; i++){
        if (i == k){
            max_without = prices[i];
        }else{
            sum_discount += 0.2 * prices[i];
        }

    }

    cout << max_without << ' ' << sum_discount << endl;

    return 0;
}
