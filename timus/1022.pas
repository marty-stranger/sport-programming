var
	n, u, v, i : integer;
	g : array [1..100, 1..100] of boolean;
	ind : array [1..100] of integer;
	b : array [1..100] of boolean;

begin
	Read(n);

	for u := 1 to n do begin
		ind[u] := 0;
		for v := 1 to n do
			g[u][v] := false;
	end;
	
	for u := 1 to n do begin
		Read(v);
		while (v <> 0) do begin
			g[u][v] := true;
			inc(ind[v]);
			Read(v);
		end;
	end;

	for u := 1 to n do
		b[u] := true;	


	for i := 1 to n do begin
		for u := 1 to n do
			if ((b[u]) and (ind[u] = 0)) then begin
				v := u;
				break;
			end;

		b[v] := false;	

		for u := 1 to n do
			if (g[v][u]) then
				dec(ind[u]);			

		if (i <> n) then
		      	Write(v, ' ')
		else
			Writeln(v);	
	end;
end.	
