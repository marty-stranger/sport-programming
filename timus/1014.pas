var
	n, k, i : integer;
	a : array [1..100] of integer;
begin
	Read(n);

	if (n = 0) then begin
		Write(10);
		exit;
	end;

	if (n = 1) then begin
		Write(1);
		exit;
	end;

	k := 0;
	for i := 9 downto 2 do
		while (n mod i = 0) do begin
			inc(k); a[k] := i;
			n := n div i;
		end;

	if (n = 1) then begin
		for i := k downto 1 do
			Write(a[i]);
		Writeln	
	end else
		Writeln(-1);	
end.
