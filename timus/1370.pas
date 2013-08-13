var
	n, m, i, t : integer;
	a : array [1..1000] of integer;
	b : array [1..10] of integer;

begin
	Read(n, m);
	m := (m-1) mod n + 1;
	
	if (m > n - 10) then begin
		for i := 1 to 10-(n-m) do
			Read(b[n-m + i]);
		for i := 10-(n-m) + 1 to m do
			Read(t);
		for i := m+1 to n do
			Read(b[i-m]);			
	end else begin
		for i := 1 to m do
			Read(t);
		for i := m+1 to m+10 do
			Read(b[i-m]);
	end;
	
	for i := 1 to 10 do
		Write(b[i]);		
end.
