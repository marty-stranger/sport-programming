#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int inf = 1e9;

int n,m,v;

int xs,ys,xf,yf;

string mp[3000];

bool mpx[5000][5000];

int d[5000][5000];

queue<pair<int, int> > q;

bool vis[5000][5000];

void ping(int x, int y, int z) {
	if (x < 0 || y < 0 || x >= n || y >= m) {
		return;
	}
	if (d[x][y] <= z) {
		return;
	}
	d[x][y] = z;
	q.push(make_pair(x,y));
}

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) {
		return;
	}
	if (d[x][y] == inf) {
		return;
	}
	if (vis[x][y]) {
		return;
	}
	vis[x][y] = true;
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x,y+1);
}

int main() {
	cin >> n >> m >> v;
	cin >> xs >> ys >> xf >> yf;
	--xs;
	--ys;
	--xf;
	--yf;

	for (int i = 0; i < n; i++) {
		cin >> mp[i];
		for (int j = 0; j < m; j++) {
			mpx[2*i][2*j] = (mp[i][j] == 'F');
		}
	}
	
	xs <<= 1;
	ys <<= 1;
	xf <<= 1;
	yf <<= 1;
	n <<= 1;
	m <<= 1;
	
	// cout << xs << " " << ys << endl;
	// cout << xf << " " << yf << endl;
	
	mpx[xs][ys] = true;
	mpx[xf][yf] = true;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			d[i][j] = inf;
			if (mpx[i][j]) {
				ping(i,j,0);
			}
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << d[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;
		// cout << "q: " << x << " " << y << endl;
		int z = d[x][y]+1;
		if (z <= v) {
			ping(x,y-1,z);
			ping(x,y+1,z);
			ping(x-1,y,z);
			ping(x+1,y,z);
		}
	}
	
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << d[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	
	dfs(xs,ys);
	
	if (vis[xf][yf]) {
		cout << "Hello, Deimos!";
	} else {
		cout << "Dire victory";
	}

}
