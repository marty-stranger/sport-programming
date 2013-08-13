var
	n, m, i, li, v, u, w, qs, qe, c : integer;
	a, d : array [1..100000] of integer;
	lv, lw, lnx: array [1..2000000] of integer;
	q : array [1..100001] of integer;
	b : array [1..100000] of boolean;

procedure add(v, u, w : integer);
begin
	inc(li); lv[li] := u; lw[li] := w; lnx[li] := a[v]; a[v] := li;
end;

begin
	read(n, m);
	li := 0;
	fillchar(a, sizeof(a), 0);
	for i := 1 to m do begin
		read(v, u, w);
		add(v, u, w);
		add(u, v, w);
	end;

	for v := 1 to n do
		d[v] := 1000000000;
	read(v);
	d[v] := 0;

	qs := 0; qe := 0;
	inc(qe); q[qe] := v;

	fillchar(b, sizeof(b), false);
	b[v] := true;

	c := 0;

	while qs <> qe do begin
		if qs = n + 1 then
			qs := 1
		else
			inc(qs);

		v := q[qs]; b[v] := false;
		li := a[v];
		while li <> 0 do begin
			u := lv[li]; w := lw[li];

			if d[v] + w < d[u] then begin
				d[u] := d[v] + w;
				inc(c);

				if not b[u] then begin
					if qe = n + 1 then
						qe := 1
					else
						inc(qe);
					q[qe] := u;
					b[u] := true;
				end;
			end;

			li := lnx[li];
		end;
	end;

	for u := 1 to n do
		write(d[u], ' ');
	writeln;

	writeln('c = ', c);
end.
