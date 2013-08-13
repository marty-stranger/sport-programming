const
	base = 100000000;
	basedigits = 8;
	maxsize = 25;

type
	tlarge = array [0..maxsize] of integer;


procedure LargeAdd(var a : tlarge; const b : tlarge);
	var
		i : integer;
		rem : integer;

	begin
		if (a[0] < b[0]) then
			a[0] := b[0];
		rem := 0;
		for i := 1 to a[0] do begin
			rem := rem + a[i] + b[i];
			a[i] := rem mod base;
			rem := rem div base;
		end;	

		if (rem <> 0) then begin
			inc(a[0]);
			a[a[0]] := rem;
		end;
		
	end;	

procedure LargeMulInt(var a : tlarge; b : integer);
	var
		i : integer;
		rem : int64;

	begin
		rem := 0;
		for i := 1 to a[0] do begin
			rem := int64(a[i]) * b + rem;
			a[i] := rem mod base;
			rem := rem div base;
		end;

		if (rem <> 0) then begin
			inc(a[0]);
			a[a[0]] := rem;
		end;
	end;	

procedure LargeWrite(const a : tlarge);
	var
		s : string [basedigits];
		i : integer;

	begin
			Write(a[a[0]]);
			for i := a[0] - 1 downto 1 do begin
				Str(a[i], s);
				while (Length(s) <> basedigits) do
					s := '0' + s;
				Write(s);	
			end;
	end;	


var               
	n, k, i : integer;
	a, b, c : tlarge;

begin
	Read(n, k);

	Fillchar(a, sizeof(a), 0);
	a[0] := 1; a[1] := 1;
	Fillchar(b, sizeof(b), 0);
	b[0] := 1; b[1] := k - 1;
	for i := 1 to n do begin
		c := b;
		LargeAdd(b, a);
		LargeMulInt(b, k - 1);
		a := c;
	end;

	LargeWrite(a);
end.
