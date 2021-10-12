#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <fstream>

using namespace std;

int main()
{
    fstream file("27-7b.txt");
    int count_s, n;
    int max_7 = INT_MIN, max_1 = INT_MIN;
    
    file >> count_s;

    for (int i = 1; i < count_s; i++) {
        file >> n;
        if (n % 7 == 0 && n % 49 != 0) {
            if (n > max_7) {
                max_7 = n;
            }
        }
        else if (n % 7 != 0){
            if (n > max_1) {
                max_1 = n;
            }
        }
    }

    cout << max_7 * max_1 << endl;

    return 0;
}
