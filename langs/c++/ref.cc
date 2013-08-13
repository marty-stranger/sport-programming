#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a;
	a.push_back(5);

	int &i = a[0];
	i = 1;
	cout << a[0];
}
