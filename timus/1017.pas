var
	n, i, j : integer;
	a : array [0..500] of int64;

begin
	Read(n);

	Fillchar(a, sizeof(a), 0);
	a[0] := 1;
	a[1] := 1;

	for i := 2 to n do
		for j := n downto i do
			inc(a[j], a[j-i]);

	Writeln(a[n] - 1);	
end.
