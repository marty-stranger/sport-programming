{$M 16777216}
const
	maxl = 1000000;

var
	l : integer;
	a : array [0..9] of string;
	r : array [1..maxl] of char;
	b : array [0..9] of boolean;

procedure go(i : integer);
var
	j, ii : integer;
begin
	b[i] := true;
	j := 1;
	while (j <= length(a[i])) and (a[i][j] <> '#') do begin
		if a[i][j] = '*' then begin
			inc(j);

			if j > length(a[i]) then
				break;
			
			ii := ord(a[i][j]) - ord('0');

			if b[ii] then begin
				l := maxl + 1;
				exit;
			end;
			
			go(ii);
		end else begin
			inc(l);
			if l > maxl then
				break;
			r[l] := a[i][j];
		end;
		inc(j);
	end;
	b[i] := false;
end;

var
	n, i : integer;
	s : string;

begin
	readln(n);

	for i := 1 to n do begin
		readln(s);
		a[i] := s;
		while (length(s) = 0) or (s[length(s)] <> '#') do begin
			a[i] := a[i] + #10;
			readln(s);
			a[i] := a[i] + s;
		end;
	end;

	l := 0;
	go(1);

	if l > maxl then
		writeln('#')
	else begin
		for i := 1 to l do
			write(r[i]);
		writeln;
	end;

end.
