const
	inf = 1000000000;

var
	d : array [1..100000] of integer;

function less(u, v : integer) : boolean;
begin
	less := d[u] < d[v];
end;

var
	hn : integer;
	h, uh : array [1..100000] of integer;

procedure down(i : integer);
var
	v, u, j : integer;
begin
	v := h[i]; j := 2*i;
	while j <= hn do begin
		if (j+1 <= hn) and less(h[j+1], h[j]) then
			inc(j);

		if not less(h[j], v) then
			break;

		u := h[j]; h[i] := u; uh[u] := i;
		i := j; j := 2*i;
	end;

	h[i] := v; uh[v] := i;
end;

procedure up(i : integer);
var
	u, v, j : integer;
begin
	v := h[i]; j := i div 2;
	while (j <> 0) and less(v, h[j]) do begin
		u := h[j]; h[i] := u; uh[u] := i;
		i := j; j := i div 2;
	end;
	h[i] := v; uh[v] := i;
end;

procedure heap_insert(u : integer);
begin
	inc(hn); h[hn] := u; uh[u] := hn;
end;

function heap_extract : integer;
begin
	heap_extract := h[1];
	h[1] := h[hn]; uh[h[1]] := 1; dec(hn);
	down(1);
end;

procedure heap_decrease(u : integer);
begin
	up(uh[u]);
end;

var
	n, m, i, li, u, v, w : integer;
	a : array [1..100000] of integer;
	lv, lw, lnx : array [1..2000000] of integer;
	b : array [1..100000] of boolean;
begin
	read(n, m);

	li := 0;
	fillchar(a, sizeof(a), 0);
	for i := 1 to m do begin
		read(u, v, w);
		inc(li); lv[li] := v; lw[li] := w; lnx[li] := a[u]; a[u] := li;
		inc(li); lv[li] := u; lw[li] := w; lnx[li] := a[v]; a[v] := li;
	end;

	hn := 0;
	for u := 1 to n do begin
		d[u] := inf;
		b[u] := true;
		heap_insert(u);
	end;

	read(u);
	d[u] := 0;

	for i := 1 to n do begin
		v := heap_extract;

		b[v] := false;

		li := a[v];
		while li <> 0 do begin
			u := lv[li]; w := lw[li];
			if b[u] and (d[v] + w < d[u]) then begin
				d[u] := d[v] + w;
				heap_decrease(u);
			end;

			li := lnx[li];
		end;
	end;

	for u := 1 to n do
		write(d[u], ' ');
	writeln;
end.
