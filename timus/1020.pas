const
	pi = 3.1415926535897932385;

var
	n, i : integer;
	x1, y1, x2, y2, x0, y0 : real;
	r, l : real;
begin
	Read(n, r);

	l := 0;
	Read(x1, y1); x0 := x1; y0 := y1;
	for i := 2 to n do begin
		Read(x2, y2);
		l := l + sqrt(sqr(x2 - x1) + sqr(y2 - y1));
		x1 := x2; y1 := y2;
	end;	
	l := l + sqrt(sqr(x1 - x0) + sqr(y1 - y0));

	l := l + 2 *pi*r;

	Writeln(l : 0 : 2);
end.	
