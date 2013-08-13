type
	integer = longint;

var
	k, p, i, x, y : integer;
	t : real;

begin
	read(k, p);
	
	i := 0;
	while (i <= 100) do begin
		for x := 0 to p-1 do begin
			if (int64(x*x) >int64(k)+p*i) then
				break;
		
			t := sqrt(real(k) + real(p) * i - real(x)*x);
			y := trunc(t);
			
			if (int64(y) * y = int64(k) + int64(p)*i - int64(x)*x) then begin
				writeln(x, ' ', y);
				exit;
			end;
		end;
		inc(i);
	end;
	
	writeln('NO SOLUTION');
end.
