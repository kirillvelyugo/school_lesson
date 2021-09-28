#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a(10000, -1000);

int game(int x) {
	if (a[x] != -1000) {
		return a[x];
	}
	if (x >= 34) {
		return a[x] = 0;
	}

	vector <int> tmp = { game(x + 1), game(x + 2), game(x + 3), game(x * 2) };
	vector <int> neg;
	int res = 0;

	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] <= 0) {
			neg.push_back(tmp[i]);
		}
	}

	if (!neg.empty()) {
		res = *max_element(neg.begin(), neg.end());
		res = -res + 1;
	}
	else {
		res = -*max_element(tmp.begin(), tmp.end());
	}

	return a[x] = res;
}

int main()
{
	for (int x = 1; x <= 33; x++) {
		int res = game(x);
		if (res == 1) {
			cout << '(' << x << ") " << res << endl;
		}
		if (res == 2) {
			cout << '(' << x << ") " << res << endl;
		}
		if (res == -2) {
			cout << '(' << x << ") " << res << endl;
		}
	}
	return 0;
}
