var
	n, k, c : integer;
begin
	for n := 1 to 15 do
		for k := 1 to n do begin
			if 2*(n mod k) > k then
				c := (n div k)*(k*(n div k) + 2*(n mod k)) + 2*(n mod k) - k
			else
				c := (n div k)*(k*(n div k) + 2*(n mod k));
			writeln(n, ' ', k, ' -> ', c, ' ', n*n - c*k);
		end;
end.
