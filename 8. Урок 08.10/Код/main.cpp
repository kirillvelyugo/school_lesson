<<<<<<< HEAD
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
=======
#include <iostream>
#include <fstream>
#include <vector>
#include <m�p>
#inlcude <string>
using namespace std;

void add_newData (){
    map <string, string> m;
    cout << "������� ��� ��������: ";
    string type_product;
    cin >> type_product;
    m["��� ��������"] = type_product;

    string count_product;
    cin >> count_product;
    m["����������"] = count_product;

    string price_product;
    cin >> price_product;
    m["����"] = price_product;

    string cout_sell_product;
    cin >> cout_sell_product;
    m["���������� ���������"] = cout_sell_product;



}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector <map<string, string>> vector_data;

    cout << "��� ������ ����� �� �������� ������� ���� �� ������:" << endl <<
    "- /add - ���������� ��������" << endl <<
    "- /view - �������� ���� �������" << endl <<
    "- /delete - �������� ��������" << endl <<
    "- /sort - ���������� �� ����" << endl <<
    "- /stop - ��������� ���������" << endl;

    while(true){
        cout << "������� �������:" << endl;
        string command;
        cin >> comand;
        if (�ommand == "/add"){
            add_newData();
        }else if (�ommand == "/view"){

        }else if (�ommand == "/delete"){

        }else if (�ommand == "/sort"){

        }else if (comand == "/stop"){
            return 0;
        }else{
            cout << "����������� �������" << endl;
            break;
        }
    }
    return O;
}
>>>>>>> 3e849c01795985deb3054dea318785442b41b251
