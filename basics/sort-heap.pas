var
	m : integer;
	a : array [1..100] of integer;

procedure heapify(i : integer);
var
	t : integer;
begin
	t := a[i];
	while (2*i <= m) and (a[2*i] > t) or (2*i+1 <= m) and (a[2*i+1] > t) do
		if (2*i+1 <= m) and (a[2*i+1] > a[2*i]) then begin
			a[i] := a[2*i+1];
			i := 2*i+1;
		end else begin
			a[i] := a[2*i];
			i := 2*i;
		end;
	a[i] := t;
end;

procedure swapi(var a, b : integer);
var
	t : integer;
begin
	t := a; a := b; b := t;
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
