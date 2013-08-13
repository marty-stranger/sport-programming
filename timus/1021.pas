var
	m, n, i, j, l, r, x : integer;
	a, b : array [1..50000] of integer;
	f : boolean;

begin
	Read(m);
	for i := 1 to m do
		Read(a[i]);

	Read(n);	
	for i := 1 to n do
		Read(b[i]);

	for i := 1 to n do
		b[i] := 10000 - b[i];

	f := false;
	i := 1; j := 1;
	while ((not f) and (i <= m) and (j <= n)) do begin
		if (a[i] = b[j]) then
			f := true;

		if (a[i] < b[j]) then
			inc(i)
		else
			inc(j);
	end;

	{f := false;
	for i := 1 to m do begin
		x := 10000 - a[i];
		l := 1; r := n;
		while (l <= r) and (not f) do begin
			j := (l + r) div 2;
			if (x < b[j]) then
				r := j - 1
			else if (x > b[j]) then
				l := j + 1
			else
				f := true;	
		end;
	end;}

	if (f) then
		Writeln('YES')
	else
		Writeln('NO');
end.
