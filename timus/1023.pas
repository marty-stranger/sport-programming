var
	k, l : integer;

begin
	Read(k);

	l := 2;

	while (k mod (l+1) <> 0) and (l+1 <= (k div 2 + 1)) do
		inc(l);
	if (k mod (l+1) = 0) then
		Writeln(l)
	else
		Writeln(k - 1);	
end.
