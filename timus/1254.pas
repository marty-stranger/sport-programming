const
	inf = 1000000000;

var
	n, m, k, i, j, xx, yy, x, y, dx, dy, sx, sy, hn : integer;
	a : array [0..76, 0..76] of boolean;
	b : array [1..76, 1..76] of boolean;
	v, s, dd, mm : double;
	d : array [1..75, 1..75] of double;
	hx, hy : array[1..76*76] of integer;
	xyh : array [1..75, 1..75] of integer;
	ch : char;

function lessxy(i, x, y : integer) : boolean;
begin
	lessxy := d[hx[i], hy[i]] < d[x, y]
end;

procedure hmove(i, j : integer);
begin
	hx[i] := hx[j]; hy[i] := hy[j];
	xyh[hx[i], hy[i]] := i;
end;

procedure down(i : integer);
var
	x, y : integer;
begin
	x := hx[i]; y := hy[i];
	while (2*i <= hn) and lessxy(2*i, x, y) or (2*i+1 <= hn) and lessxy(2*i+1, x, y) do
		if (2*i+1 <= hn) and (d[hx[2*i+1], hy[2*i+1]] < d[hx[2*i], hy[2*i]]) then begin
			hmove(i, 2*i+1);
			i := 2*i+1;
		end else begin
			hmove(i, 2*i);
			i := 2*i;
		end;
	hx[i] := x; hy[i] := y; xyh[x, y] := i;
end;

procedure up(i : integer);
var
	x, y : integer;
begin
	x := hx[i]; y := hy[i];
	while (i <> 1) and (d[x][y] < d[hx[i div 2], hy[i div 2]]) do begin
		hmove(i, i div 2);
		i := i div 2;
	end;
	hx[i] := x; hy[i] := y; xyh[x, y] := i;
end;

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
		hn := 0;
		for x := 1 to m do 
			for y := 1 to n do begin
				d[x][y] := inf;
				b[x][y] := a[x][y];
				inc(hn); hx[hn] := x; hy[hn] := y;
				xyh[x][y] := hn;
			end;

		d[sx][sy] := 0;
		up(xyh[sx][sy]);

		for j := 1 to m*n do begin
			xx := hx[1]; yy := hy[1];
			hx[1] := hx[hn]; hy[1] := hy[hn];
			xyh[hx[1], hy[1]] := 1;
			dec(hn);
			down(1);

			b[xx][yy] := false;

			for dx := -1 to 1 do
				for dy := -1 to 1 do
					if (dx <> 0) or (dy <> 0) then begin
						x := xx + dx; y := yy + dy;
						dd := sqrt(1.0*dx*dx + dy*dy);
						if b[x][y] and (d[xx][yy] + dd < d[x][y]) then begin
							d[x][y] := d[xx][yy] + dd;
							up(xyh[x][y]);
						end;
					end;
		end;

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
