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
