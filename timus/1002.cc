#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const unsigned int no_edge = 60000;

int main() {
	const char corr[] = "22233344115566070778889990";

	string num; cin >> num;
	while (num != "-1") {
		int m = num.length();

		vector<vector<unsigned short> > g(m+1, vector<unsigned  short>(m+1, no_edge));

		int n; cin >> n;
		vector<string> dict(n);

		for(unsigned short i = 0; i < n; ++i) {
			cin >> dict[i];

			int l = dict[i].length();
			string tmp = dict[i];
			for (int j = 0; j < l; ++j)
				tmp[j] = corr[tmp[j] - 'a'];

			int j = num.find(tmp, 0);
			while (j != -1) {
				g[j][j+l] = i;
				j = num.find(tmp, j+1);

			}	
		}

		bool f = false;
		vector<char> p(m+1, -1);	

		queue<char> q;
		q.push(0);
		p[0] = -1;
		while (!q.empty() && !f) {
			int u = q.front(); q.pop();

			for (int v = 0; v <= m; ++v)
				if (g[u][v] != no_edge && p[v] == -1) {
					q.push(v); p[v] = u;
					if (v == m) {
						f = true;
						break;
					}
				}
		}

		if (f) {
			vector<unsigned short> ans(m); int k = 0;
			int u = m;
			while (p[u] != -1) {
				ans[k++] = g[p[u]][u];
				u = p[u];
			}

			for (int i = k-1; i > 0; --i)
				cout << dict[ans[i]] << ' ';
			cout << dict[ans[0]] << endl;
		} else
			cout << "No solution." << endl;

		cin >> num;	
	}	
	return 0;
}
