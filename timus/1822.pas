{$M 16777216}
const
	eps = 1e-7;

var
	gi, gu, gn, t : array [1..10000] of integer;
	b : array [1..100000] of boolean;
	m : double;

procedure dfs1(u, tt : integer);
var
	i, v : integer;
begin
	if tt < 0 then
		b[u] := false;

	i := gi[u];
	while i <> 0 do begin
		v := gu[i];
		dfs1(v, tt - t[v]);
		i := gn[i];
	end;
end;

function dfs2(u : integer) : boolean;
var
	i, c, cc, v : integer;
begin
	if not b[u] then begin
		dfs2 := false;
		exit;
	end;

	c := 0; cc := 0;
	i := gi[u];
	while i <> 0 do begin
		v := gu[i];
		if dfs2(v) then
			inc(c);
		inc(cc);

		i := gn[i];
	end;

	dfs2 := cc*m <= c;
end;

var
	n, u, v, f, mt : integer;
	l, r : double;
begin
	read(n, mt);

	f := 0;
	fillchar(gi, sizeof(gi), 0);
	fillchar(b, sizeof(b), true);
	for u := 2 to n do begin
		read(v, t[u]);
		inc(f); gu[f] := u; gn[f] := gi[v]; gi[v] := f;
	end;

	dfs1(1, mt);

	l := 0; r := 1;
	while l < r - eps do begin
		m := (l + r) / 2;
		if dfs2(1) then
			l := m
		else
			r := m
	end;

	writeln(l * 100 : 0 : 4);
end.
