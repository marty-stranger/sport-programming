const
	eps = 1e-8;

var
	c, d : integer;
	x, y : double;

function search2(xx, yy : double) : double;
var
	l, r, m1, m2, xxx, yyy, d1, d2 : double;
begin
	l := -d; r := d;
	while l < r - eps do begin
		m1 := (2*l + r) / 3;
		m2 := (l + 2*r) / 3;

		xxx := c - m1; yyy := sqrt(sqr(d) - sqr(m1));
		d1 := sqrt(sqr(xx - xxx) + sqr(yy - yyy)) + sqrt(sqr(x - xxx) + sqr(y - yyy));

		xxx := c - m2; yyy := sqrt(sqr(d) - sqr(m2));
		d2 := sqrt(sqr(xx - xxx) + sqr(yy - yyy)) + sqrt(sqr(x - xxx) + sqr(y - yyy));

		if d1 < d2 then
			r := m2
		else
			l := m1;
	end;

	search2 := d1;
end;

var
	a, b : integer;
	l, r, m1, m2, yy, d1, d2 : double;

begin
	read(a, b, c, d);

	if (a <= d) or (b <= d) then begin
		if (a <= d) and (b <= d) then
			writeln(0.0 : 0 : 3)
		else if a <= d then
			writeln(2.*(b - d) : 0 : 3)
		else 
			writeln(2.*(a - d) : 0 : 3);
		exit;
	end;

	x := (c*c + a*a - b*b)*1. / (2*c);
	y := sqrt(a*a - x*x);

	l := -d; r := d;
	while l < r - eps do begin
		m1 := (2*l + r) / 3;
		m2 := (l + 2*r) / 3;

		yy := sqrt(sqr(d) - sqr(m1));
		d1 := sqrt(sqr(x - m1) + sqr(y - yy)) + search2(m1, yy);

		yy := sqrt(sqr(d) - sqr(m2));
		d2 := sqrt(sqr(x - m2) + sqr(y - yy)) + search2(m2, yy);

		if d1 < d2 then
			r := m2
		else
			l := m1;
	end;

	writeln(d1 : 0 : 3);
end.
