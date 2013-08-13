function gcd(a, b : integer) : integer;
var
	t : integer;
begin
	while b <> 0 do begin
		t := a mod b; a := b; b := t;
	end;

	gcd := a;
end;

var
	n, i, j, d, dd : integer;
	a, b : array [1..130000] of integer;

begin
	read(n);

	fillchar(b, sizeof(b), 0);
	for i := 1 to n do begin
		read(a[i]);
		b[a[i]] := i;
	end;

	d := 0; i := 0;
	for j := 1 to 130000 do
		if b[j] <> 0 then begin
			inc(i);
			d := gcd(d, abs(b[j] - i));
		end;

	dd := 0; i := 0;
	for j := 130000 downto 1 do
		if b[j] <> 0 then begin
			inc(i);
			dd := gcd(dd, abs(b[j] - i));
		end;

	if (d = 0) or (dd = 0) then
		writeln(n - 1)
	else if d > dd then
		writeln(d - 1)
	else
		writeln(dd - 1);
end.
