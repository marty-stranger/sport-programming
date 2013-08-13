const
	inf = 1000000000;

var
	n, u, v, i : integer;
	g : array [1..100, 1..100] of integer;
	b : array [1..100] of boolean;
	d : array [1..100] of integer;

begin
	read(n);
	for u := 1 to n do
		for v := 1 to n do
			read(g[u][v]);

	for u := 1 to n do begin
		d[u] := inf;
		b[u] := true;
	end;

	read(u);
	d[u] := 0;

	for i := 1 to n do begin
		v := 0;
		for u := 1 to n do
			if b[u] and ((v = 0) or (d[u] < d[v])) then
				v := u;

		b[v] := false;
		for u := 1 to n do
			if b[u] and (d[v] + g[v][u] < d[u]) then
				d[u] := d[v] + g[v][u];
	end;

	for i := 1 to n do
		write(d[u], ' ');
	writeln;
end.
