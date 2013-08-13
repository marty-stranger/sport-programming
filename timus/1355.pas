{$ifdef fpc}
type
	integer = longint;
{$endif}

var
	n, m, i, j, k, l : integer;
	s : string [5];
	a, b : array [1..5000] of integer;
	c : array [1..5000] of boolean;
	f : boolean;
	a1, b1 : integer;
	c1 : boolean;

procedure Exchange(i, j : integer);	
	begin
		a1 := a[i]; a[i] := a[j]; a[j] := a1;
		b1 := b[i]; b[i] := b[j]; b[j] := b1;
		c1 := c[i]; c[i] := c[j]; c[j] := c1;
	end;	
		
begin
	Read(n);
	while (n <> -1) do begin
		Readln(m);

		f := true; i := 0; k := 0;
		while ((i <> m) and (f)) do begin
			inc(i); inc(k);
			Readln(a[k], b[k], s); c[k] := (s = ' odd');

			j := k-1;
			while (j > 0) and (a[j] >= a[k]) do
				dec(j);
			inc(j);

			while (j <> k) and (a[j] = a[k]) do begin
				if (b[j] > b[k]) then begin
					Exchange(j, k);
				end else if (b[j] = b[k]) then begin
                                	f := (c[j] = c[k]);
                                        dec(k);
                                        j := k;
				end else begin
					a[k] := b[j]+1;
					c[k] := c[k] xor c[j];
				end;

				while (j < k) and (a[j] < a[k]) do
					inc(j);
			end;

			a1 := a[k]; b1 := b[k]; c1 := c[k];
			for l := k downto j+1 do begin
				a[l] := a[l-1];	b[l] := b[l-1];	c[l] := c[l-1];
			end;
			a[j] := a1; b[j] := b1; c[j] := c1;
		end;

                if (f) then
			Writeln(i)
                else
                	Writeln(i-1);

                for l := i + 1 to m do
                	Readln(a1, b1, s);

		Read(n);
	end;
end.
