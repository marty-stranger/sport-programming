type
	real = double;

var
	x1, y1, x2, y2, x, y, l, a, b : real;

function SP(x1, y1, x2, y2 : real) : real;
	begin
		SP := x1*x2 + y1*y2;
	end;

function CM(x1, y1, x2, y2 : real) : real;
	begin
		CM := x1*y2 - x2*y1;
	end;

function Dist(x1, y1, x2, y2 : real) : real;
	begin
		Dist := Sqrt(Sqr(x2 - x1) + Sqr(y2 - y1));
	end;


function Max(a, b : real) : real;
	begin
		if (a > b) then
			Max := a
		else
			Max := b;
	end;

begin
	//Assign(input, '2.in'); Reset(input);

	Read(x1, y1, x2, y2, x, y, l);

	if (SP(x - x1, y - y1, x2 - x1, y2 - y1) <= 0) then
		a := Dist(x, y, x1, y1)
        else if (SP(x - x2, y - y2, x1 - x2, y1 - y2) <= 0) then
		a := Dist(x, y, x2, y2)
	else begin
		a := abs(CM(x1 - x, y1 - y, x2 - x, y2 - y) / Dist(x1, y1, x2, y2));
	end;

	if (a > l) then
		Writeln(a - l : 0 : 2)
	else
		Writeln('0.00');

	b := Max(Dist(x, y, x1, y1), Dist(x, y, x2, y2));

	if (b > l) then
		Writeln(b - l : 0 : 2)
	else
		Writeln('0.00');
end.
