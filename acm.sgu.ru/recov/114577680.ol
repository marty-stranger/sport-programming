int main() {
	const double inf = 1e12;
	const double eps = 1e-8;
	int b; cin >> b;
	stable ss;
	ss.x = b;

	vector<stable> s;
	s.push_back(ss);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		stable ss;
		cin >> ss.x;
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			horse h; cin >> h.v >> h.d;
			ss.h.push_back(h);
		}
		s.push_back(ss);
	}

	sort(s.begin(), s.end());

	n = s.size();
	vector<double> c(n, inf);
	for (int i = 0; i < n; i++)
		if (s[i].x == 0)
			c[i] = 0;
		else
			break;

	for (int i = 0; i < n; i++) {
		if (s[i].x > b)
			break;
		int m = s[i].h.size();
		for (int j = 0; j < m; j++) {
			int k = i+1;
			while (k < n && s[i].x + s[i].h[j].d >= s[k].x) {
				c[k] = min(c[k], c[i] + (double)(s[k].x - s[i].x) / s[i].h[j].v);
				k++;
			}
		}
	}
	
	int i;
	for (i = 0; i < n; i++)
		if (s[i].x == b)
			break;

	if (fabs(c[i] - inf) < eps)
		cout << -1;
	else {
		cout.setf(ostream::fixed);
		cout.precision(3);
		cout << c[i];	
	}

	return 0