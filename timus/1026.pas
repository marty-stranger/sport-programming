var
	n, i, j, k : integer;
	a : array [1..100000] of integer;
	b : array [1..5000] of integer;
	s : string;

procedure Sort;
	var
		i, j, k : integer;

	begin
		Fillchar(b, sizeof(b), 0);
		for i := 1 to n do
			inc(b[a[i]]);

		k := 0;
		for i := 1 to 5000 do
			for j := 1 to b[i] do begin
				inc(k); a[k] := i;
			end;		
	end;	

begin
	Read(n);
	for i := 1 to n do
		Read(a[i]);

	Sort;

        Readln; Readln(s);

	Read(k);
	for i := 1 to k do begin
		Read(j);		
		Writeln(a[j]);
	end;	
end.
