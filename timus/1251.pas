const
	dx : array [1..8] of integer = (1, 1, 0, -1, -1, -1, 0, 1);
	dy : array [1..8] of integer = (0, 1, 1, 1, 0, -1, -1, -1);

var
	fhl, hl : integer;
	fhx, fhy, hx, hy, cx, cy : array [1..10000] of integer;
	xyt, xyh, xyc : array [1..100, 1..100] of integer;
	event : char;

function less(i, j : integer) : boolean;
var
	dx, dy : integer;
begin
	dx := fhx[i] - fhx[j];
	dy := fhy[i] - fhy[j];
	
	less := (dx < 0) or (dx = 0) and (dy < 0);
end;

procedure iswap(var a, b : integer);
var
	t : integer;
begin
	t := a; a := b; b := t;
end;

procedure fhswap(i, j : integer);
begin
	iswap(fhx[i], fhx[j]);
	iswap(fhy[i], fhy[j]);
end;

procedure fheapify(i : integer);
begin
	if (2*i+1 <= fhl) and less(2*i+1, 2*i) and less(2*i+1, i) then begin
		fhswap(i, 2*i+1);
		fheapify(2*i+1);
	end else if (2*i <= fhl) and less(2*i, i) then begin
		fhswap(i, 2*i);
		fheapify(2*i);
	end;
end;

procedure fheapifyUp(i : integer);
begin
	if (i div 2 > 0) and less(i, i div 2) then begin
		fhswap(i div 2, i);
		fheapifyUp(i div 2);
	end;
end;

function less2(i, j : integer) : boolean;
var
	dt, dx, dy : integer;
begin
	dt := xyt[hx[i], hy[i]] - xyt[hx[j], hy[j]];
	dx := hx[i] - hx[j];
	dy := hy[i] - hy[j];

	less2 := (dt < 0) or (dt = 0) and ((dx < 0) or (dx = 0) and (dy < 0));
end;

procedure hswap(i, j : integer);
begin
	iswap(hx[i], hx[j]);
	iswap(hy[i], hy[j]);
	xyh[hx[i], hy[i]] := i;
	xyh[hx[j], hy[j]] := j;
end;

procedure heapify(i : integer);
begin
	if (2*i+1 <= hl) and less2(2*i+1, 2*i) and less2(2*i+1, i) then begin
		hswap(i, 2*i+1);
		heapify(2*i+1);
	end else if (2*i <= hl) and less2(2*i, i) then begin
		hswap(i, 2*i);
		heapify(2*i);
	end;
end;

procedure heapifyUp(i : integer);
begin
	if (i div 2 > 0) and less2(i, i div 2) then begin
		hswap(i div 2, i);
		heapifyUp(i div 2);
	end;
end;

var
	m, n, x, y, c, i, cc, di, xx, yy, cnt, t : integer;

begin
	read(m, n);

	fhl := 0;
	for x := 1 to m do
		for y := 1 to n do begin
			xyt[x, y] := -1;
			inc(fhl); fhx[fhl] := x; fhy[fhl] := y;
		end;

	fillchar(xyc, sizeof(xyc), 0);

	hl := 0;

	c := 0; cnt := 0;
	while not seekeof do begin
		read(t, event, event);

		if event = 'd' then begin
			inc(c);
			readln;

			while hl > 0 do begin
				x := hx[1]; y := hy[1];
				if xyt[x, y] < t then begin
					inc(fhl); fhx[fhl] := x; fhy[fhl] := y;
					fheapifyUp(fhl);

					hx[1] := hx[hl]; hy[1] := hy[hl]; dec(hl);
					xyh[hx[1], hy[1]] := 1;
					if hl > 0 then
						heapify(1);
				end else
					break;
			end;

			if fhl > 0 then begin
				x := fhx[1]; y := fhy[1];
				fhx[1] := fhx[fhl]; fhy[1] := fhy[fhl]; dec(fhl);
				if fhl > 0 then
					fheapify(1);

				xyc[x, y] := c;
				cx[c] := x; cy[c] := y;
				xyt[x, y] := t + 1000;

				inc(hl); hx[hl] := x; hy[hl] := y;
				xyh[x][y] := hl;
				heapifyUp(hl);
			end else
				inc(cnt);
		end else begin
			readln(cc);

			x := cx[cc]; y := cy[cc];
			if (x <> 0) and (xyc[x, y] = cc) and (t <= xyt[x, y]) then begin
				xyt[x, y] := t + 1000;
				heapify(xyh[x, y]);

				for di := 1 to 8 do begin
					xx := x + dx[di]; yy := y + dy[di];
					if (1 <= xx) and (xx <= m) and (1 <= yy) and (yy <= n) and
							(t <= xyt[xx, yy]) and (t + 100 > xyt[xx, yy]) then begin
						xyt[xx, yy] := t + 100;
						heapify(xyh[xx, yy]);
					end;
				end;
			end;
		end;
	end;

	writeln(cnt);
end.
