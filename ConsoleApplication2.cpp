#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct studends {
	string surname;
	string name;
	vector <int> marks;
};

vector <studends> data_studendts;

string take_part(string &s) {
	string part;
	int p = s.find(',');
	part = s.substr(0, p);
	s.erase(s.begin(), s.begin() + p + 1);

	return part;
}

void open_file() {
	fstream file("marks.csv");
	
	string s;
	while (getline(file, s)) {
		s += ",";
		studends student;
		vector <int> mark;

		student.surname = take_part(s);
		student.name = take_part(s);

		while (s.size()) {
			int m = atoi(take_part(s).c_str());
			mark.push_back(m);
		}

		student.marks = mark;
		data_studendts.push_back(student);
	}
}

void average_mark() {
	int alg_avg = 0, rus_avg = 0, fiz_avg = 0, his_avg = 0;
	for (int i = 0; i < data_studendts.size(); i++) {
		

		alg_avg += data_studendts[i].marks[0]; 
		rus_avg += data_studendts[i].marks[1];
		fiz_avg += data_studendts[i].marks[2];
		his_avg += data_studendts[i].marks[3];

	}

	cout << "Средний балл по алгебре: " << alg_avg / 1000. << endl
		<< "Средний балл по русскому языку: " << rus_avg / 1000. << endl
		<< "Средний балл по физике: " << fiz_avg / 1000. << endl
		<< "Средний балл по истории: " << his_avg / 1000. << endl << endl;
}

void print_vector(vector <string> names) {
	sort(names.begin(), names.end());
	for (auto x : names) {
		cout << x << endl;
	}
	cout << endl;
}

void maxSum_mark() {
	int max_sum = 0;
	vector <string> names;
	for (int i = 0; i < data_studendts.size(); i++) {
		string name;
		int tmp_sum = 0;
		for (auto x : data_studendts[i].marks) {
			tmp_sum += x;
		}
		if (tmp_sum > max_sum) {
			names.clear();
			max_sum = tmp_sum;
			name = data_studendts[i].surname + " " + data_studendts[i].name;
			names.push_back(name);
		}
		else if (tmp_sum == max_sum) {
			name = data_studendts[i].surname + " " + data_studendts[i].name;
			names.push_back(name);
		}
	}
	cout << "Максимальный набранный балл: " << max_sum << endl << endl;
	print_vector(names);
}

void count_mark() {
	int count = 0;
	for (int i = 0; i < data_studendts.size(); i++) {
		for (auto x : data_studendts[i].marks) {
			if (x == 2) {
				count++;
				break;
			}
		}
	}
	
	cout << "Количество двоек: " << count << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	open_file();
	
	average_mark();
	maxSum_mark();
	count_mark();

	return 0;
}
