var
	a : array [1..100] of integer;

procedure s(l, r : integer);
var
	i, j, p, t : integer;

begin
	if l < r then begin
		i := l; j := r; p := a[(l + r) div 2];
		while i <= j do
			if a[i] < p then
				inc(i)
			else if a[j] > p then
				dec(j)
			else begin
				t := a[i]; a[i] := a[j]; a[j] := t;
				inc(i); dec(j);
			end;

		s(l, j); s(i, r);
	end;
end;
       
var
	n, i : integer;

begin
	read(n);
	for i := 1 to n do
		read(a[i]);

	s(1, n);

	for i := 1 to n do
		write(a[i], ' ');
	writeln;
end.
