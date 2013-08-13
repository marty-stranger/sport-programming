var
	n, m, i, li, v, u, w, qs, qe, c, ql : integer;
	a, d : array [1..100000] of integer;
	lv, lw, lnx: array [1..2000000] of integer;
	q : array [1..100001] of integer;
	b, bb : array [1..100000] of boolean;

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

	qs := 0; qe := 0; ql := 0;
	inc(qe); q[qe] := v; inc(ql);

	fillchar(b, sizeof(b), false); // reached
	fillchar(bb, sizeof(bb), false); // in queue
	
	c := 0;

	b[v] := true;

	while qs <> qe do begin
		if qs = n + 1 then
			qs := 1
		else
			inc(qs);

		dec(ql);

		v := q[qs];
		bb[v] := true;
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
					inc(ql);
					if ql > n then begin
						writeln('fuckup');
						exit;
					end;
					q[qe] := u;
					b[u] := true;
				end else if bb[u] then begin
					if qs = 0 then
						qs := n + 1;
					q[qs] := u;
					if qs = 1 then
						qs := n + 1
					else
						dec(qs);
					inc(ql);
					if ql > n then begin
						writeln('fuckup');
						exit;
					end;
					bb[u] := false;
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
