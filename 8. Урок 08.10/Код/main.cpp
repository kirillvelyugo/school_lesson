#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <string>
using namespace std;

void load_dataFrom (vector <map<string, string>> &vector_data){
    fstream file("data_base.txt");
    string s;
    int n;
    while (file){
        map <string, string> m;

        file >> n;
        m["index"] = n;

        file >> s;
        m["name"] = s;

        file >> s;
        m["surname"] = s;

        file >> s;
        m["middle-name"] = s;

        file >> s;
        m["birthday"] = s;

        vector_data.push_back(m);
    }
}
void load_dataTo (vector <map<string, string>> &vector_data){
    fstream file("data_base.txt", ios::out | ios::trunc);
    for (int i = 0; i < vector_data.size(); i++){
        file << vector_data[i]["index"] << ' '
        << vector_data[i]["name"] << ' '
        << vector_data[i]["surname"] << ' '
        << vector_data[i]["middle-name"] << ' '
        << vector_data[i]["birthday"] << endl;
    }
}

void add_newData (vector <map<string, string>> &vector_data){
    map <string, string> m;
    string s;

    m["index"] = to_string(vector_data.size());

    cout << "������� ���: ";
    cin >> s;
    m["name"] = s;

    cout << "������� �������: ";
    cin >> s;
    m["surname"] = s;

    cout << "������� ��������: ";
    cin >> s;
    m["middle-name"] = s;

    cout << "������� ���� ��������: ";
    cin >> s;
    m["birthday"] = s;

    vector_data.push_back(m);
    load_dataTo(vector_data);
}

void view_data (vector <map<string, string>> &vector_data){
    // iomanip setw ����� ������������ ����� �
    // ������ � ������� ������
    if (vector_data[1]["index"] != "1"){
        cout << "It's clear" << endl;
        return;
    }
    cout << setw(10) <<"Index" << ' '
    << setw(10) <<"Name" << ' '
    << setw(10) <<"Surname" << ' '
    << setw(10) <<"Middle-name" << ' '
    << setw(10) <<"Birthday" << endl;

    for (auto x: vector_data){
        cout << x["index"] << ' '
        << x["name"] << ' '
        << x["surname"] << ' '
        << x["middle-name"] << ' '
        << x["birthday"] << endl;
    }
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
            view_data(vector_data);
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
