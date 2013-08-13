type
	triplet = array[1..3] of double;

var
	b : array [1..2000] of triplet;
	p : array [1..2000] of integer;

const
	eps = 1e-8;

function less(i, j : integer) : boolean;
var
	k : integer;
begin
	for k := 1 to 3 do
		if b[i][k] < b[j][k] then begin
			less := true;
			exit;
		end else if b[i][k] > b[j][k] then begin
			less := false;
			exit;
		end;

	less := false;
end;

procedure sort(l, r : integer);
var
	i, j, x, t : integer;
begin
	if l < r then begin
		i := l; j := r; x := p[l + random(r - l)];
		while i <= j do
			if less(p[i], x) then
				inc(i)
			else if less(x, p[j]) then
				dec(j)
			else begin
				t := p[i]; p[i] := p[j]; p[j] := t;
				inc(i); dec(j);
			end;

		sort(i, r); sort(l, j);
	end;
end;

var
	n, i, j, k, c, m : integer;
	a : array [1..2000, 1..3] of integer;
	f : boolean;
	d : double;
begin
	randomize;

	read(n);

	if n = 1 then begin
		writeln(1);
		exit;
	end;

	for i := 1 to n do
		for k := 1 to 3 do
			read(a[i][k]);

	m := 2;
	for i := 1 to n do begin
		for j := 1 to n do begin
			for k := 1 to 3 do
				b[j][k] := a[j][k] - a[i][k];

			d := 0;
			for k := 1 to 3 do
				if abs(b[j][k]) > d then
					d := abs(b[j][k]);

			if d <> 0 then
				for k := 1 to 3 do
					b[j][k] := b[j][k] / d;
			p[j] := j;

			if (j <> i) and (d = 0) then
				halt(2);
		end;

		sort(1, n);

		c := 1;
		for j := 2 to n do begin
			f := true;
			for k := 1 to 3 do
				if b[p[j]][k] <> b[p[j - 1]][k] then begin
					f := false;
					break;
				end;

			if f then
				inc(c)
			else begin
				if c + 1 > m then
					m := c + 1;
				c := 1;
			end;
		end;

		if c + 1 > m then
			m := c + 1;
	end;

	writeln(m);
end.
