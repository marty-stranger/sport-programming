type
	tt = record x : integer; end;
var
	x : integer;
	t : tt;
begin
	x := 5;
	with t as a do a.x := x;
	writeln(t.x);
end.
