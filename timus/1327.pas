var
	a, b : integer;

begin
	Read(a, b);
	if (a mod 2 = 0) then
		inc(a);
	if (b mod 2 = 1) then
		inc(b);
	Writeln((b - a + 1) div 2);
end.
