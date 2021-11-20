#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    fstream file("b.txt");
    vector <int> nums;
    int max_length = INT_MIN;

    int count_n, n;
    file >> count_n;
    for (int i = 0; i < count_n; i++){
        file >> n;
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end());

    for (int i = 1; i <= 100; i++){
        int tmp_length = 0;
        for (int j = 0; j < nums.size(); j ++){
            int num = nums[j];
            while (binary_search(nums.begin(), nums.end(), num)){
                tmp_length++;
                max_length = max(max_length, tmp_length);
                num += i;
            }
            tmp_length = 0;
        }
    }

    cout << max_length << endl;

    return 0;
}
