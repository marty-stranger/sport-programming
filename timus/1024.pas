var	
	n, i, j, k: integer;
	a, c : array [1..1000] of integer;
	b : array [1..1000] of boolean;
	v : int64;

function GCD(a, b : integer) : integer;
	var
		c : integer;

	begin
		while (b <> 0) do begin
			c := b;
			b := a mod b;
			a := c;
		end;

		GCD := a;
	end;	

begin
	Read(n);
	for i := 1 to n do
		Read(a[i]);

	for i := 1 to n do
		b[i] := true;


	k := 0;	
	for i := 1 to n do
		if (b[i]) then begin
			j := a[i]; b[i] := false;
			inc(k); c[k] := 1;
			while (j <> i) do begin
				b[j] := false;
				j := a[j];
				inc(c[k]);
			end;

		end;

	v := c[1];
	for i := 2 to k do begin
		v := v * c[i] div GCD(v, c[i]);
	end;	

	Writeln(v);
end.
