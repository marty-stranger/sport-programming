procedure p(a : array of integer);
begin
	writeln(length(a));
end;

var
	a : array [1..100] of integer;

begin
	p(a);
end.
