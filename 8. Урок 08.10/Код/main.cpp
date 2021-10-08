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
