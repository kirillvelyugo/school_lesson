#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Books {
    string title;
    string name;
    int count;
};

vector <Books> d;


int max_sizeField(int n){
    int mx_s = 0;
    switch (n){
    case 1:
        for (auto x: d){
            int tmp = x.title.size();
            mx_s = max(tmp, mx_s);
        }
        if (mx_s < 9){
            mx_s = 9;
        }
        break;
    case 2:
        for (auto x: d){
            int tmp = x.name.size();
            mx_s = max(tmp, mx_s);
        }
        if (mx_s < 5){
            mx_s = 5;
        }
        break;
    case 3:
        for (auto x: d){
            int tmp = to_string(x.count).size();
            mx_s = max(tmp, mx_s);
        }
        if (mx_s < 18){
            mx_s = 18;
        }
        break;
    }
    return mx_s + 1;
}

void print (){

    int max_sizeField__title = max_sizeField(1);
    int max_sizeField__name = max_sizeField(2);
    int max_sizeField__count = max_sizeField(3);

    cout << setw(max_sizeField__title) << "Заголовок" <<
            setw(max_sizeField__name) << "Автор" <<
            setw(max_sizeField__count) << "Количество страниц" << endl;

    for (auto x: d){
            cout << setw(max_sizeField__title) << x.title <<
                    setw(max_sizeField__name) << x.name <<
                    setw(max_sizeField__count) << x.count << endl;
    }
}

void add (){
    Books B;
    cout << "Введите название книги:" << endl;
    cin >> B.title;
    cout << "Введите автора книги:" << endl;
    cin >> B.name;
    cout << "Введите количество книг:" << endl;
    cin >> B.count;

    d.push_back(B);
}

void remove (){

}

void sort (){

}

void open (){
    fstream file("base.txt");
    string s;
    getline(file, s);
    int count_s = atoi(s.c_str());

    for (int i = 0; i < count_s; i++){
        string title;
        getline(file, title);
        string name;
        getline(file, name);
        string c;
        getline (file, c);

        Books B = { title, name, atoi(c.c_str()) };

        d.push_back(B);
    }
}

void close(){
}

int main()
{
    setlocale(LC_ALL, "Russian");
    open();

    while (true){
        cout << "/view - Просмотреть записи" << endl
         << "/add - Добавить запись" << endl
         << "/del - Удаление записи" << endl
         << "/sort - Сортировка" << endl;
        cout << "Для выбора действия введите команду:" << endl << endl;

        string command;
        cin >> command;

        if (command == "/view"){
            print();
        }
        else if (command == "/add"){
            add();
        }
        else if (command == "/del"){

        }
        else if (command == "/sort"){

        }
        else if(command == "/finish"){
            // close();
            return 0;
        }else{
            cout << "Неверная команда!" << endl << endl;
        }
    }

    return 0;
}
