var
	n, m, i, j : integer;
	a, b : array [1..3000] of integer;

begin
	read(n, m);

	fillchar(a, sizeof(a), 0);

	for i := 1 to n do begin
		for j := 1 to m do
			read(b[j]);

		for j := 1 to m-1 do
			if a[j] + a[j+1] + b[j] + b[j+1] = 3 then begin
				writeln('No');
				exit;
			end;

		a := b;
	end;

	writeln('Yes');
end.
