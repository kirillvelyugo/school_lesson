#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void load_dataFrom (vector <map<string, string>> &vector_data){
    fstream file("data_base.txt");
    string s;
    while (file){
        map <string, string> m;
        file >> s;
        m["���"] = s;

        file >> s;
        m["�������"] = s;

        file >> s;
        m["��������"] = s;

        file >> s;
        m["���� ��������"] = s;

        vector_data.push_back(m);
    }
}
void load_dataTo (vector <map<string, string>> &vector_data){
    fstream file("data_base.txt", ios::out | ios::trunc);
    for (int i = 0; i < vector_data.size(); i++){
        cout << vector_data[i]["���"] << ' '
        << vector_data[i]["�������"] << ' '
        << vector_data[i]["��������"] << ' '
        << vector_data[i]["���� ��������"] << endl;
    }
}

void add_newData (vector <map<string, string>> &vector_data){
    map <string, string> m;
    string s;

    cout << "������� ���: ";
    cin >> s;
    m["���"] = s;

    cout << "������� �������: ";
    cin >> s;
    m["�������"] = s;

    cout << "������� ��������: ";
    cin >> s;
    m["��������"] = s;

    cout << "������� ���� ��������: ";
    cin >> s;
    m["���� ��������"] = s;

    vector_data.push_back(m);
    load_dataTo(vector_data);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector <map<string, string>> vector_data;
    load_dataFrom(vector_data);

    cout << "��� ������ ����� �� �������� ������� ���� �� ������:" << endl <<
    "- /add - ���������� ��������" << endl <<
    "- /view - �������� ���� �������" << endl <<
    "- /delete - �������� ��������" << endl <<
    "- /sort - ���������� �� ����" << endl <<
    "- /stop - ��������� ���������" << endl;

    while(true){
        cout << "������� �������:" << endl;
        string command;
        cin >> command;
        if (command == "/add"){
            add_newData(vector_data);
        }else if (command == "/view"){

        }else if (command == "/delete"){

        }else if (command == "/sort"){

        }else if (command == "/stop"){
            return 0;
        }else{
            cout << "����������� �������" << endl;
        }
    }
    return 0;
}
