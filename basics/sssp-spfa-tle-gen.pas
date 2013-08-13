var
	n, m, i : integer;
begin
	randomize;

	n := 50000;
	m := n - 1 + n - 2;

	writeln(n, ' ', m);

	for i := n downto 2 do
		writeln(1, ' ', i, ' ', 1000000000 div i);

	for i := 3 to n do
		writeln(i - 1, ' ', i, ' ', 1);

	writeln(1);
end.
