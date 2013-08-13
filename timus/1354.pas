var
	k, i, d : integer;
	a : array [1..20000] of char;
	b : array [0..255] of boolean;

function IsPol(n : integer) : boolean;
	var
		i : integer;
		b : boolean;

	begin
		b := true;

		for i := 1 to (n + 1) div 2 do
			if (a[i] <> a[n-i+1]) then
				b := false;

		IsPol := b;		
	end;

begin
	//Assign(input, '8.in'); Reset(input);

	fillchar(b, sizeof(b), false);

	k := 0;
	while (not eoln) do begin
		inc(k);
		Read(a[k]);
		b[Ord(a[k])] := true;
	end;

	for d := 1 to k do begin
		for i := k+1 to k+d do
			a[i] := a[k+d-i+1];

		if (IsPol(k+d)) then begin
			for i := 1 to k+d do
				Write(a[i]);

			exit;
		end;
	end;
end.
