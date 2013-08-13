int main() {
	int n; cin >> n;
	g = vector<vector<edge> >(n);
	for (int i = 0; i < n-1; i++) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		string s; cin >> s;
		g[v].push_back(edge(u, i, s == "protected"));
		if (s == "almost")
			cin >> s;
	}

	rec(0, 0);

	int m = e.size();
	cout << m << endl;
	for (int i = 0; i < m; i++)
		cout << e[i]+1 << ' ';

	return 0