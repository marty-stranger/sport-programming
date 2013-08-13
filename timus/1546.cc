// ok
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<string> s;

struct cmp {
	inline bool operator()(int i1, int i2) {
		return c(s[i1], s[i2]) < 0;
	}

	inline int c(string &s1, string &s2) {
		int l1 = s1.length();
		int l2 = s2.length();
		int i = 0; int j = 0, d = 0;
		while (i < l1 && j < l2)
			if (isdigit(s1[i]) && isdigit(s2[j])) {
				int i1 = i, j1 = j;
				while (i < l1 && s1[i] == '0')
					i++;
				while (j < l2 && s2[j] == '0')
					j++;

				int i2 = i, j2 = j;
				while (i < l1 && isdigit(s1[i]))
					i++;
				while (j < l2 && isdigit(s2[j]))
					j++;

				if (i - i2 != j - j2)
					return i - i2 - (j - j2);

				for (int ii = 0; ii < i - i2; ii++)
					if (s1[i2 + ii] != s2[j2 + ii])
						return s1[i2 + ii] - s2[j2 + ii];

				if (i - i1 != j - j1 && d == 0)
					d = j - j1 - (i - i1);
			} else {
				if (s1[i] != s2[j])
					return s1[i] - s2[j];
				i++;
				j++;
			}
	
		if (i < l1)
			return 1;
		if (j < l2)
			return -1;

		if (d != 0)
			return d;
	
		return 0;
	}
};

int main() {
	vector<int> p;
	char t[100*1024];

	int n = 0;
	while (scanf("%s", t) == 1) {
		s.push_back(string(t));
		p.push_back(n);
		n++;
	}

	sort(p.begin(), p.end(), cmp());

	for (int i = 0; i < n; i++)
		puts(s[p[i]].c_str());
		
	return 0;
}
