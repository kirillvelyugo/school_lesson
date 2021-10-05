#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    fstream file("27-6b.txt");
    int max_2 = INT_MIN, max_3 = INT_MIN, max_6 = INT_MIN, max_1 = INT_MIN;
    int s;
    file >> s;

    while (file){
        int n;
        file >> n;

        if (n % 2 == 0 && n % 3 != 0){
            if (n > max_2){
                max_2 = n;
            }
        }
        else if (n % 3 == 0 && n % 2 != 0){
            if (n > max_3){
                max_3 = n;
            }
        }
        else if (n % 6 == 0){
            if (n > max_6){
                max_6 = n;
            }
        }
        else {
            if (n > max_1){
                max_1 = n;
            }
        }
    }

    int p_23 = max_2 * max_3,
        p_26 = max_2 * max_6,
        p_36 = max_3 * max_6,
        p_16 = max_1 * max_6;

    cout << max(max(p_23,p_26), max(p_36, p_16));
    return 0;
}
