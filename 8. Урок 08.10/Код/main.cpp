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
        m["Имя"] = s;

        file >> s;
        m["Фамилия"] = s;

        file >> s;
        m["Отчество"] = s;

        file >> s;
        m["Дата рождения"] = s;

        vector_data.push_back(m);
    }
}
void load_dataTo (vector <map<string, string>> &vector_data){
    fstream file("data_base.txt", ios::out | ios::trunc);
    for (int i = 0; i < vector_data.size(); i++){
        cout << vector_data[i]["Имя"] << ' '
        << vector_data[i]["Фамилия"] << ' '
        << vector_data[i]["Отчество"] << ' '
        << vector_data[i]["Дата рождения"] << endl;
    }
}

void add_newData (vector <map<string, string>> &vector_data){
    map <string, string> m;
    string s;

    cout << "Введите имя: ";
    cin >> s;
    m["Имя"] = s;

    cout << "Введите фамилию: ";
    cin >> s;
    m["Фамилия"] = s;

    cout << "Введите отчество: ";
    cin >> s;
    m["Отчество"] = s;

    cout << "Введите дату рождения: ";
    cin >> s;
    m["Дата рождения"] = s;

    vector_data.push_back(m);
    load_dataTo(vector_data);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector <map<string, string>> vector_data;
    load_dataFrom(vector_data);

    cout << "Для выбора одной из операции введите одну из команд:" << endl <<
    "- /add - добавление элемента" << endl <<
    "- /view - просмотр всех записей" << endl <<
    "- /delete - удаление элемента" << endl <<
    "- /sort - сортировка по полю" << endl <<
    "- /stop - остановка программы" << endl;

    while(true){
        cout << "Введите команду:" << endl;
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
            cout << "Неизвестная команда" << endl;
        }
    }
    return 0;
}
=======
#include <iostream>
#include <fstream>
#include <vector>
#include <mаp>
#inlcude <string>
using namespace std;

void add_newData (){
    map <string, string> m;
    cout << "Введите тип продукта: ";
    string type_product;
    cin >> type_product;
    m["Тип продукта"] = type_product;

    string count_product;
    cin >> count_product;
    m["Количетсво"] = count_product;

    string price_product;
    cin >> price_product;
    m["Цена"] = price_product;

    string cout_sell_product;
    cin >> cout_sell_product;
    m["Количетсво проданных"] = cout_sell_product;



}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector <map<string, string>> vector_data;

    cout << "Для выбора одной из операции введите одну из команд:" << endl <<
    "- /add - добавление элемента" << endl <<
    "- /view - просмотр всех записей" << endl <<
    "- /delete - удаление элемента" << endl <<
    "- /sort - сортировка по полю" << endl <<
    "- /stop - остановка программы" << endl;

    while(true){
        cout << "Введите команду:" << endl;
        string command;
        cin >> comand;
        if (сommand == "/add"){
            add_newData();
        }else if (сommand == "/view"){

        }else if (сommand == "/delete"){

        }else if (сommand == "/sort"){

        }else if (comand == "/stop"){
            return 0;
        }else{
            cout << "Неизвестная команда" << endl;
            break;
        }
    }
    return O;
}
>>>>>>> 3e849c01795985deb3054dea318785442b41b251
