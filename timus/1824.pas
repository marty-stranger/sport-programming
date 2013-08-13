var
	n, mc, mm : integer;
	g : array [1..30] of integer;

procedure go(exc, cnt, cov, dom : integer);
var
	a, u, v, w: integer;
	f : boolean;

begin
	// writeln('go: ', 'exc = ', exc, ' cnt = ', cnt, ' cov = ', cov, ' dom = ', dom);
	f := true;
	while f do begin
		for u := 1 to n do if (1 shl (u - 1)) and not exc and not dom <> 0 then
			for v := 1 to n do if (v <> u) and ((1 shl (v - 1)) and not exc and not dom <> 0) then
				if (g[u] and not cov) and (g[v] and not cov) = g[u] and not cov then begin
					exc := exc or (1 shl (u - 1));
					break;
				end;

		f := false;
		for u := 1 to n do
			if (1 shl (u - 1)) and not cov <> 0 then begin
				w := 0;
				for v := 1 to n do
					if ((1 shl (v - 1)) and not dom and not exc <> 0) and
							((1 shl (u - 1)) and (g[v] and not cov) <> 0) then
						if w = 0 then
							w := v
						else begin
							w := 0;
							break;
						end;

				if w <> 0 then begin
					dom := dom or (1 shl (w - 1));
					cov := cov or g[w];
					inc(cnt);
					f := true;
				end;
			end;
	end;

	if cov = (1 shl n) - 1 then begin
		if cnt < mc then begin
			mc := cnt;
			// writeln('mc = ', mc);
			mm := dom;
		end;
		exit;
	end;

	for u := 1 to n do
		if (1 shl (u - 1)) and not cov and not exc <> 0 then begin
			go(exc or (1 shl (u - 1)), cnt, cov, dom);
			go(exc, cnt + 1, cov or g[u], dom or (1 shl (u - 1)));
			break;
		end;
end;

var
	r, u, v : integer;
	x, y : array [1..30] of integer;
begin
	read(n, r);
	for u := 1 to n do
		read(x[u], y[u]);

	fillchar(g, sizeof(g), 0);
	for u := 1 to n do
		for v := 1 to n do begin
			if sqr(x[u]-x[v]) + sqr(y[u]-y[v]) <= r*r then begin
				g[u] := g[u] or (1 shl (v - 1));
				g[v] := g[v] or (1 shl (u - 1));
			end;
		end;

	mc := 1000000000;
	go(0, 0, 0, 0);

	writeln(mc);
	for u := 1 to n do
		if mm and (1 shl (u - 1)) <> 0 then
			write(u, ' ');
	writeln;
end.
