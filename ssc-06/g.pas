procedure swapInt(var a, b : integer);
var
	t : integer;
begin
	t := a; a := b; b := t;
end;

var
	sx, sy1, sy2, sri : array [1..2*60000+2] of integer;

procedure sort1(l, r : integer);
var
	i, j, px, py : integer;
begin
	if l < r then begin
		i := l; j := r; px := sx[(l + r) div 2]; py := sy1[(l + r) div 2];
		while i <= j do
			if (sx[i] < px) or (sx[i] = px) and (sy1[i] < py) then
				inc(i)
			else if (px < sx[j]) or (px = sx[j]) and (py < sy1[j]) then
				dec(j)
			else begin
				swapInt(sx[i], sx[j]);
				swapInt(sy1[i], sy1[j]);
				swapInt(sy2[i], sy2[j]);
				swapInt(sri[i], sri[j]);
				inc(i); dec(j);
			end;

		sort1(l, j); sort1(i, r);
	end;
end;

var
	s, ss : array [0..60000] of int64;

procedure sort2(l, r : integer);
var
	i, j, p : integer;
	t : int64;
begin
	if l < r then begin
		i := l; j := r; p := ss[(l + r) div 2];
		while i <= j do
			if ss[i] < p then
				inc(i)
			else if ss[j] > p then
				dec(j)
			else begin
				t := ss[i]; ss[i] := ss[j]; ss[j] := t;
				inc(i); dec(j);
			end;

		sort2(l, j); sort2(i, r);
	end;
end;

type
	pInt = ^integer;

var
	troot, tf : integer;
	tl, tr, tk, tv : array [1..2*60000+2] of integer;

procedure treeInsert(k, v : integer);
var
	i : ^integer;
begin
	i := @troot;
	while i^ <> 0 do begin
		// writeln('treeInsert: i^ = ', i^);
		if k < tk[i^] then
			i := @tl[i^]
		else
			i := @tr[i^];
	end;

	inc(tf); tk[tf] := k; tv[tf] := v; tl[tf] := 0; tr[tf] := 0;
	i^ := tf;
end;

function treeFind(k : integer) : pInt;
var
	i : ^integer;
begin
	i := @troot;
	while (i^ <> 0) and (tk[i^] <> k) do
		if k < tk[i^] then
			i := @tl[i^]
		else
			i := @tr[i^];
	// writeln('treeFind: i^ = ', i^);

	treeFind := i;
end;

procedure treeDelete(i : pInt);
var
	j : ^integer;
begin
	if (tl[i^] = 0) and (tr[i^] = 0) then
		i^ := 0
	else if tl[i^] = 0 then
		i^ := tr[i^]
	else if tr[i^] = 0 then
		i^ := tl[i^]
	else begin
		j := @tr[i^];
		while tl[j^] <> 0 do
			j := @tl[j^];
		tv[i^] := tv[j^];
		j^ := tr[j^];
	end;
end;

function treeSucc(i : integer) : integer;
begin
	i := tr[i];
	if i = 0 then begin
		treeSucc := 0;
		exit;
	end;

	while tl[i] <> 0 do
		i := tl[i];
	treeSucc := i;
end;

var
	n, x, y, x1, y1, x2, y2, i, si, ti, ri : integer;
	p : array [1..60000] of integer;

begin
	read(n, x, y);

	si := 0;
	inc(si); sx[si] := 0; sy1[si] := 0; sy2[si] := y; sri[si] := 0;
	inc(si); sx[si] := x; sy1[si] := 0; sy2[si] := y; sri[si] := 0;

	s[0] := int64(x) * y;

	for i := 1 to n do begin
		read(x1, y1, x2, y2);
		if x1 > x2 then
			swapInt(x1, x2);
		if y1 > y2 then
			swapInt(y1, y2);

		inc(si); sx[si] := x1; sy1[si] := y1; sy2[si] := y2; sri[si] := i;
		inc(si); sx[si] := x2; sy1[si] := y1; sy2[si] := y2; sri[si] := i;

		s[i] := int64(x2 - x1) * (y2 - y1);
	end;

	sort1(1, 2*n+2);

	troot := 0; tf := 0;
	for i := 1 to 2*n + 2 do begin
		// writeln('sx = ', sx[i]);
		if treeFind(sy1[i])^ <> 0 then begin
			treeDelete(treeFind(sy1[i]));
			treeDelete(treeFind(sy2[i]));
		end else begin
			treeInsert(sy1[i], sri[i]);
			treeInsert(sy2[i], -sri[i]);

			ti := treeSucc(treeFind(sy2[i])^);
			if ti <> 0 then begin
				// writeln('ti = ', ti);
				ri := tv[ti];
				// writeln('ri = ', ri);
				if ri > 0 then
					p[sri[i]] := p[ri]
				else
					p[sri[i]] := -ri;
				// writeln('p: ', sri[i], ' -> ', p[sri[i]]);
			end;
		end;
	end;

	ss := s;
	for i := 1 to n do
		dec(ss[p[i]], s[i]);

	sort2(0, n);

	for i := 0 to n do
		write(ss[i], ' ');
	writeln;
end.
