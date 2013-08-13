var
	n, i, k, u, v : integer;
	b : array [1..20000] of boolean;
	a, next : array [1..20000] of integer;
	c : array [0..20000] of integer;
	x, y : array [1..20000] of integer;

procedure DFS(v : integer; d : integer);
	var
		i : integer;
                f : boolean;

	begin
		b[v] := false;

                x[v] := d;
		y[v] := c[d];
		inc(c[d]);

		for i := 1 to 2*n-2 do
			if (b[a[i]]) and (next[i] = v) then begin
                                DFS(a[i], d+1);
			end;
        end;

begin
	//Assign(input, '12.in'); Reset(input);

	Read(n);

	k := 0;
        for i := 1 to n-1 do begin
                Read(u, v);
                inc(k);
                a[k] := u;
                next[k] := v;
                inc(k);
		a[k] := v;
		next[k] := u;
	end;

	fillchar(c, sizeof(c), 0);
	fillchar(b, sizeof(b), true);

	DFS(1, 0);

	for i := 1 to n do
		Writeln(x[i], ' ', y[i]);
end.
