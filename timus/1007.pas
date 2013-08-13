var
	n, m, sum, i, j, k : integer;
	a : array [1..10001] of integer;
	b : array [1..10002] of integer;
	ch : char;

begin
	Readln(n);

	while (not seekeof) do begin
		m := 0;
		b[1] := 0;
                while (not seekeoln) do begin
                	inc(m);
                        Read(ch);
                        a[m] := ord(ch) - ord('0');
                        inc(b[1], a[m]);
                end;
		Readln;

		sum := 0;
		for i := 1 to m do
			if (a[i] = 1) then begin
				b[i+1] := b[i] - 1;
				sum := sum + i;
			end else
				b[i+1] := b[i];

		if (m = n - 1) then begin
			for i := 1 to n do begin
				if ((sum + b[i]) mod (n + 1) = 0) then begin
					j := i;
					k := 0;
					break;
				end;
				if ((sum + i + b[i]) mod (n + 1) = 0) then begin
					j := i;
					k := 1;
					break;
				end;
			end;

			for i := 1 to j - 1 do
				Write(a[i]);
			Write(k);
			for i := j to m do
				Write(a[i]);
		end else if (m = n + 1) then begin
			for i := 1 to m do begin
				if ((a[i] = 0) and ((sum - b[i + 1]) mod (n + 1) = 0)) then begin
					j := i;
					break;
				end;
				if ((a[i] = 1) and ((sum - i - b[i + 1]) mod (n + 1) = 0)) then begin
					j := i;
					break;
				end;
			end;

			for i := 1 to j - 1 do
				Write(a[i]);
			for i := j + 1 to m do
				Write(a[i]);
		end else if (sum mod (n + 1) = 0) then begin
			for i := 1 to m do
				Write(a[i]);
		end else begin
			for i := 1 to m do begin
				if ((a[i] = 1) and ((sum - i) mod (n + 1) = 0)) then begin
					k := 0;
					j := i;
					break;
				end;
			end;

			for i := 1 to j-1 do
				Write(a[i]);
			Write(k);	
			for i := j + 1 to m do
				Write(a[i]);
		end;

		Writeln;		
	end;
end.
