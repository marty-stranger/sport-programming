var
	n, mc, mm : integer;
	gl, gc : array [1..30] of integer;
	g : array [1..30, 1..30] of integer;
	gm : array [1..30] of integer;

procedure go(u, c, m, ma : integer);
var
	i, j, v, w, nm, nma : integer;
begin
	writeln('u = ', u, ' c = ', c);
	if c >= mc then
		exit;

	while (u <= n) and (ma and (1 shl u) <> 0) do
		inc(u);

	if u = n + 1 then begin
		if c < mc then begin
			mc := c;
			writeln('mc = ', mc);
			mm := m;
		end;
		exit;
	end;

	for i := gl[u] downto 1 do begin
		v := g[u][i];
		nm := m or (1 shl v);
		nma := ma or gm[v];
		go(u + 1, c + 1, nm, nma);
	end;
end;

var
	r, u, v : integer;
	x, y : array [1..30] of integer;
begin
	read(n, r);
	for u := 1 to n do
		read(x[u], y[u]);

	fillchar(gl, sizeof(gl), 0);
	fillchar(gm, sizeof(gm), 0);
	fillchar(gc, sizeof(gm), 0);
	for u := 1 to n do
		for v := 1 to n do begin
			if sqr(x[u]-x[v]) + sqr(y[u]-y[v]) <= r*r then begin
				inc(gl[u]); g[u][gl[u]] := v;
				inc(gl[v]); g[v][gl[v]] := u;
				gm[u] := gm[u] or (1 shl v);
				gm[v] := gm[v] or (1 shl u);
			end;
		end;

	mc := 1000000000;
	go(1, 0, 0, 0);

	writeln(mc);
	for u := 1 to n do
		if mm and (1 shl u) <> 0 then
			write(u, ' ');
	writeln;
end.
