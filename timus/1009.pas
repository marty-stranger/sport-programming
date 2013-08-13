var               
	n, k, i, a, b, c : integer;

begin
	Read(n, k);

	a := 1;
	b := k - 1;
	for i := 1 to n do begin
		c := b;
		b := (a + b) * (k - 1);
		a := c;
	end;

	Write(a);
end.
