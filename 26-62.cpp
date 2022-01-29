#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

struct zak {
    int price;
    string type;
};

vector <zak> v;

int take_data(){
    fstream file("26.txt");

    int n, m;
    file >> n >> m;

    for (int i = 0; i < n; i++){
        zak tmp;
        int price;
        string type;
        file >> price >> type;
        tmp.price = price;
        tmp.type = type;
        v.push_back(tmp);
    }
    return m;
}

void test_print(int n){
    for (int i = 0; i < n; i++){
        cout << v[i].price << ' ' << v[i].type << endl;
    }
}

void sort_struct(){
    for (int i = 0; i < v.size() - 1; i++){
        for (int j = v.size() - 2; j >= 0; j--){
            if (v[j].price > v[j + 1].price || v[j].price == v[j + 1].price && v[j].type > v[j + 1].type){
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main()
{
    int m = take_data();
    sort_struct();

    vector <zak> used;
    vector <zak> rest;
    for (int i = 0; i < v.size(); i++){
        if (m - v[i].price >= 0){
            m -= v[i].price;
            used.push_back(v[i]);
        }else if (v[i].type == "Q"){
            rest.push_back(v[i]);
        }
    }

    for (int i = used.size() - 1; i >= 0; i--){
        if (used[i].type == "Z"){
            if (m + used[i].price >= rest[0].price){
                m = m + used[i].price - rest[0].price;
                used[i] = rest[0];
                rest.erase(rest.begin());
            }
        }
    }

    int count = 0;
    for (int i = 0; i < used.size(); i++){
        if (used[i].type == "Q"){
            count++;
        }
    }
    cout << count << ' ' << m << endl;

    return 0;
}
