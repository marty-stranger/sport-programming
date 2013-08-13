var
	n, i, sum, max : integer;
	a : array [1..20] of integer;


procedure Search(i, x : integer);
	begin		
		if (2*x > sum) then
			exit;

		if (i = n) then begin
			if (x > max) then
				max := x;
			exit;	
		end;

		inc(i);		
		Search(i, x + a[i]);
		Search(i, x);		
	end;	

begin
	Read(n);
	sum := 0;
	for i := 1 to n do begin
		Read(a[i]);
		inc(sum, a[i]);
	end;	

	max := 0;
	Search(0, 0);	

	Writeln(sum - 2*max);
end.
