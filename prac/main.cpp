#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

struct perf{
    string surname;
    string name;
    vector <int> mark;
};

vector <perf> v;

string read_com (string &s){
    string n;
    for (int i = 0; i < s.size(); i++){
        if (s[i] != ','){
            n += s[i];
        }else{
            break;
        }
    }
    s.erase(s.begin(), s.begin() + n.size() + 1);
    return n;
}

void readData (){
    fstream file("marks.csv");
    string s;
    while (getline(file, s)){
        s += ',';
        perf p;
        p.surname = read_com(s);
        p.name = read_com(s);

        vector <int> m;
        for (int i = 0; i <= 3; i++){
            int n = atoi(read_com(s).c_str());
            m.push_back(n);
        }
        p.mark = m;
        v.push_back(p);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    readData();
    for (int i = 0; i < v.size(); i++){
        cout << v[i].surname << ' ' << v[i].name << ' ' << v[i].mark[0] << endl;
    }

    //cout << v[0].surname << ' ' << v[0].name << ' ' << v[0].mark[3] << endl;


    return 0;
}
