procedure swapi(var a, b : integer);
var
	t : integer;
begin
	t := a; a := b; b := t;
end;

var
	eu, ev, ew : array [1..100] of integer;

procedure sort(l, r : integer);
var
	i, j, p : integer;
begin
	if l < r then begin
		i := l; j := r; p := ew[(l + r) div 2];
		while i <= j do
			if ew[i] < p then
				inc(i)
			else if ew[j] > p then
				dec(j)
			else begin
				swapi(eu[i], eu[j]);
				swapi(ev[i], ev[j]);
				swapi(ew[i], ew[j]);
				inc(i); dec(j);
			end;

		sort(i, r); sort(l, j);
	end;
end;

var
	n, m, i, u, l, ct : integer;
	c : array [1..100] of integer;

begin
	read(n, m);

	for i := 1 to m do
		read(eu[i], ev[i], ew[i]);

	sort(1, m);

	for u := 1 to n do
		c[i] := i;

	l := 0;
	for i := 1 to m do
		if c[eu[i]] <> c[ev[i]] then begin
			ct := c[eu[i]];
			for u := 1 to n do
				if c[u] = ct then
					c[u] := c[ev[i]];
			inc(l, ew[i]);
		end;

	writeln(l);
end.
