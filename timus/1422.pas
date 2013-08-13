var 
	n, i, j, k, l, ii, f, h, m : integer;
	x, y, z : array [1..2000] of integer;
	dx, dy, dz : array [1..2000] of double;
	d : double;

	t : array [0..2000] of integer;
	li, lc, ln : array [1..2000] of integer;

	hd : double;
	yes : boolean;

function max(a, b : double) : double;
begin
	if a > b then
		max := a
	else
		max := b;
end;

begin
	read(n);

	if n = 1 then begin
		writeln('1');
		exit;
	end;

	for i := 1 to n do
		read(x[i], y[i], z[i]);

	m := 2;
	for i := 1 to n do begin
		f := 0;

		fillchar(t, sizeof(t), 0);
		for j := i + 1 to n do begin
			dx[j] := x[j] - x[i]; dy[j] := y[j] - y[i]; dz[j] := z[j] - z[i];

			if dx[j] < 0 then begin
				dx[j] := -dx[j]; dy[j] := -dy[j]; dz[j] := -dz[j];
			end else if (dx[j] = 0) and (dy[j] < 0) then begin
				dy[j] := -dy[j]; dz[j] := -dz[j];
			end else if (dx[j] = 0) and (dy[j] = 0) and (dz[j] < 0) then begin
				dz[j] := -dz[j];
			end;

			d := max(dx[j], max(dy[j], dz[j]));
			dx[j] := dx[j] / d; dy[j] := dy[j] / d; dz[j] := dz[j] / d;

			hd := dx[j];
			hd := hd * 10000000 + dy[j];
			hd := hd * 10000000 + dz[j];

			h := trunc(2000 * frac(hd * 0.6180339887));

			k := t[h];
			while k <> 0 do begin
				ii := li[k];
				
				if (dx[ii] = dx[j]) and
						(dy[ii] = dy[j]) and
					 	(dz[ii] = dz[j]) then begin
					inc(lc[k]);
					if lc[k] + 1 > m then
						m := lc[k] + 1;
					break;
				end;

				k := ln[k];
			end;

			if k = 0 then begin
				inc(f); li[f] := j; lc[f] := 1; ln[f] := t[h]; t[h] := f;
			end;
		end;
	end;

	writeln(m);
end.
