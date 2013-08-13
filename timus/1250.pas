{$M 16777216}

const
	dx : array [1..8] of integer = (1, 0, -1, 0, 1, 1, -1, -1);
	dy : array [1..8] of integer = (0, 1, 0, -1, 1, -1, 1, -1);
var
	n, m, k : integer;
	a : array [0..501, 0..501] of char;

procedure dfs1(x, y : integer);
var
	i : integer;
begin
	a[x][y] := 's';

	for i := 1 to 8 do
		if a[x + dx[i], y + dy[i]] = '.' then
			dfs1(x + dx[i], y + dy[i]);
end;

procedure dfs2(x, y : integer);
var
	i : integer;
begin
	if a[x][y] = '#' then begin
		a[x][y] := 'x';
		for i := 1 to 4 do
			if a[x + dx[i], y + dy[i]] in ['.', '#'] then
				dfs2(x + dx[i], y + dy[i]);
	end else begin
		a[x][y] := 'x';
		for i := 1 to 8 do
			if a[x + dx[i], y + dy[i]] in ['.', '#'] then
				dfs2(x + dx[i], y + dy[i]);
	end;
end;

procedure dfs3(x, y : integer);
var
	i : integer;
begin
	a[x][y] := 'x';

	for i := 1 to 4 do
		if a[x + dx[i], y + dy[i]] = '#' then
			dfs3(x + dx[i], y + dy[i]);
end;

var
	sx, sy, x, y : integer;
begin
	readln(n, m, sy, sx);

	fillchar(a, sizeof(a), 'o');

	for x := 1 to m do begin
		for y := 1 to n do
			read(a[x][y]);
		readln;
	end;

	dfs1(sx, sy);

	for x := 1 to m do begin
		if a[x][1] in ['#', '.'] then
			dfs2(x, 1);
		if a[x][n] in ['#', '.'] then
			dfs2(x, n);
	end;

	for y := 1 to n do begin
		if a[1][y] in ['#', '.'] then
			dfs2(1, y);
		if a[m][y] in ['#', '.'] then
			dfs2(m, y);
	end;

	k := 0;

	for x := 1 to m do
		for y := 1 to n do
			if a[x][y] = '#' then begin
				inc(k);
				dfs3(x, y);
			end;

	writeln(k);
end.

