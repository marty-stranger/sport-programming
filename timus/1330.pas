var
	n, m, i, s, t : integer;
	a : array [0..10000] of integer;

begin
	Read(n);
	a[0] := 0;  
	for i := 1 to n do begin 
		Read(s);
		a[i] := a[i-1] + s;
	end;	

	Read(m);	
	for i := 1 to m do begin
		Read(s, t);
		Writeln(a[t] - a[s-1]);
	end;
end.	
