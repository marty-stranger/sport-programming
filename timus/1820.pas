var
	n, k : integer;
begin
	read(n, k);

	if n <= k then
		writeln(2)
	else
		if 2*n mod k = 0 then
			writeln(2*n div k)
		else
			writeln(2*n div k + 1);
end.
