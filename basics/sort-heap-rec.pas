var
	m : integer;
	a : array [1..100] of integer;

procedure swapi(var a, b : integer);
var
	t : integer;
begin
	t := a; a := b; b := t;
end;

procedure heapify(i : integer);
begin
	if (2*i+1 <= m) and (a[2*i+1] > a[i]) and (a[2*i+1] > a[2*i]) then begin
		swapi(a[2*i+1], a[i]);
		heapify(2*i+1);
	end else if (2*i <= m) and (a[2*i] > a[i]) then begin
		swapi(a[2*i], a[i]);
		heapify(2*i);
	end;
end;

var
	n, i : integer;
begin
	read(n);
	for i := 1 to n do
		read(a[i]);

	m := n;
	for i := m div 2 downto 1 do
		heapify(i);

	for i := m downto 2 do begin
		swapi(a[1], a[i]);
		dec(m);
		heapify(1);
	end;

	for i := 1 to n do
		write(a[i], ' ');
	writeln;
end.
