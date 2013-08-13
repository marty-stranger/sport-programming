var
	n, i, k : integer;
	a : array [1..101] of integer;

procedure Sort(l, r : integer);
	var
		i, j : integer;
		x, t : integer;

	begin
		i := l; j := r; x := a[(l + r) div 2];
		repeat
			while (a[i] < x) do
				inc(i);
			while (a[j] > x) do
				dec(j);

			if (i <= j) then begin
				t := a[i]; a[i] := a[j]; a[j] := t;
				inc(i); dec(j);
			end;	
		until (i > j);

		if (i < r) then
			Sort(i, r);
		if (j > l) then
			Sort(l, j);	
	end;	

begin
	Read(n);
	for i := 1 to n do
		Read(a[i]);

	Sort(1, n);

	k := 0;
	for i := 1 to (n div 2 + 1) do
		inc(k, a[i] div 2 + 1);

	Writeln(k);	
end.
