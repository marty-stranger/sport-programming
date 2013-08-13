#include <iterator>
#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, int> m;

	m["3mar"] = 3;
	map<string, int>::iterator it = m.insert(m.begin(), make_pair("1jan", 1));
	it = m.insert(it, make_pair("2feb", 2));

	for (map<string, int>::iterator i = m.begin(); i != m.end(); i++) {

		if (i->second == 2)
			m.erase(i++);
		cout << i->first << "->" << i->second << " ";
	}

	/* it++;

	cout << it->first << " " << it->second << endl;

	m.erase(it);

	cout << it->first << " " << it->second << endl; */

	return 0;
}
