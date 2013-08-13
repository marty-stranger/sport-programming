const
	dx : array [1..4] of integer = (0, 1,  0, -1);
	dy : array [1..4] of integer = (1, 0, -1,  0);

var
	n, m, s1, s2, k, x, y, x1, y1, x2, y2, d : integer;
	b : array [0..101, 0..101] of boolean;

begin
	{assign(input, 'h.in'); reset(input);}

	read(n, m);
	
	read(x1, y1, x2, y2);
	
	for x := 0 to n+1 do
		for y := 0 to m+1 do
			b[x][y] := false;
	
	for x := 1 to n do
		for y := 1 to m do
			b[x][y] := true;
	
	s1 := -1; s2 := -1;
	x := 1; y := 1; d := 1; b[x][y] := false;
	
	k := 0;
	while (s1 = -1) or (s2 = -1) do begin
		if (x = x1) and (y = y1) then
			s1 := k;
		if (x = x2) and (y = y2) then begin
			s2 := k;
		end;	
		
		if (b[x + dx[d]][y + dy[d]]) then begin
			b[x][y] := false;
			inc(k);		
			x := x + dx[d];
			y := y + dy[d];
		end else
			d := d mod 4 + 1;
	end;	
	
	writeln(abs(s2 - s1));
end.
