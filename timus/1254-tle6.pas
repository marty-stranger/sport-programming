const
	inf = 1000000000;

var
	n, m, k, i, j, xx, yy, x, y, dx, dy, sx, sy : integer;
	a : array [0..76, 0..76] of boolean;
	b : array [1..76, 1..76] of boolean;
	v, s, dd, mm : double;
	d : array [1..75, 1..75] of double;
	ch : char;

begin
	readln(n, m, k, v);

	fillchar(a, sizeof(a), false);
	for x := 1 to m do begin
		for y := 1 to n do begin
			read(ch);
			a[x][y] := ch = '.';
		end;
		readln;
	end;

	read(sy, sx);

	i := 1; s := 0;
	while i <= k do begin
		for x := 1 to m do 
			for y := 1 to n do begin
				d[x][y] := inf;
				b[x][y] := a[x][y];
			end;

		d[sx][sy] := 0;

		for j := 1 to m*n do begin
			mm := inf;
			for x := 1 to m do 
				for y := 1 to n do
			       		if b[x][y] and (d[x][y] < mm) then begin
						mm := d[x][y];
						xx := x; yy := y;
					end;

			b[xx][yy] := false;

			for dx := -1 to 1 do
				for dy := -1 to 1 do
					if (dx <> 0) or (dy <> 0) then begin
						x := xx + dx; y := yy + dy;
						dd := sqrt(1.0*dx*dx + dy*dy);
						if b[x][y] and (d[xx][yy] + dd < d[x][y]) then begin
							d[x][y] := d[xx][yy] + dd;
						end;
					end;
		end;

		for x := 1 to m do begin
			for y := 1 to n do
				write(d[x][y] : 0 : 3, ' ');
			writeln;
		end;
		writeln;


		readln(y, x); inc(i);
		while (i <= k) and (d[x][y] = inf) do begin
			readln(y, x); inc(i);
		end;

		if d[x][y] <> inf then
			s := s + d[x][y];

		sx := x; sy := y;
	end;

	writeln(s / v : 0 : 2);
end.
