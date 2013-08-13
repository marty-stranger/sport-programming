type
	real = double;

var
	d, x1, y1, x2, y2, x, y : real;
	n, i : integer;


begin
 	Read(d, x1, y1, x2, y2, n);
	for i := 1 to n do begin
		Read(x, y);

                if (x * y2 - x2 * y >= 0) and (x * y1 - x1 * y <= 0) and (x*x + y *y <= d*d) then
                	Writeln('YES')
                else
                	Writeln('NO');	
	end;	
end.
