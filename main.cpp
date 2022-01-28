#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct data_files {
    string name;
    int size;
    string type;
    string date_create;
    string date_change;
    string level_access;
};

vector <data_files> vec_data_files;

string take_substr(string &s){
    int pos = s.find(',');
    string sub = s.substr(0, pos);
    s.erase(s.begin(), s.begin() + pos + 1);

    return sub;
}

void open_file (){
    fstream f("files.csv");

    string s;
    while(getline(f, s)){
        s += ',';
        data_files tmp;
        tmp.name = take_substr(s);
        tmp.size = atoi(take_substr(s).c_str());
        tmp.type = take_substr(s);
        tmp.date_create = take_substr(s);
        tmp.date_change = take_substr(s);
        tmp.level_access = take_substr(s);

        vec_data_files.push_back(tmp);
    }
}

void count_type(){
    int count_aud = 0, count_vid = 0, count_pic = 0,
        count_pres = 0, count_tex = 0, count_tab = 0;
    for (auto x: vec_data_files){
        if (x.type == "аудио"){
            count_aud++;
        }
        if (x.type == "видео"){
            count_vid++;
        }
        if (x.type == "изображение"){
            count_pic++;
        }
        if (x.type == "презентация"){
            count_pres++;
        }
        if (x.type == "текстовый"){
            count_tex++;
        }
        if (x.type == "электронная таблица"){
            count_tab++;
        }
    }

    cout << "Количество аудио файлов: " << count_aud << endl
         << "Количество видео файлов: " << count_vid << endl
         << "Количество изображений: " << count_pic << endl
         << "Количество презентаций: " << count_pres << endl
         << "Количество текстовых файлов: " << count_tex << endl
         << "Количество электронных таблиц: " << count_tab << endl << endl;
}

void sort_size_name(){
    for (int i = 0; i < vec_data_files.size() - 1; i++){
        for (int j = vec_data_files.size() - 1; j >= 1; j--){
            if (vec_data_files[j].size > vec_data_files[j - 1].size){
                swap(vec_data_files[j], vec_data_files[j - 1]);
            }else if (vec_data_files[j].size == vec_data_files[j - 1].size &&
                      vec_data_files[j].name < vec_data_files[j - 1].name){
                swap(vec_data_files[j], vec_data_files[j - 1]);
            }
        }
    }
}

void print_most_large_files(){
    for (int i = 0; i < 10; i++){
        cout << vec_data_files[i].name << ' ' << vec_data_files[i].size << endl;
    }
    cout << endl;
}

void most_large_files(){
    sort_size_name();
    cout << "Список 10 самых больших файлов: " << endl;
    print_most_large_files();
}


int main()
{
    setlocale(LC_ALL, "Russian");

    open_file();
    count_type();
    most_large_files();

    return 0;
}
