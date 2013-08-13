var
	n, m, mm, i, j, k, l : integer;
	s, ss : string;
	a, aa : array [1..100] of string;
	t : array [1..100] of integer;
	b : array [1..100] of boolean;
	ts : string;

begin
	readln(n);
	for i := 1 to n do begin
		readln(s);
		j := pos(' ', s);
		a[i] := copy(s, 1, j);
		ss := copy(s, j+1, length(s) - j);
		t[i] := (ord(ss[1]) - ord('0'))*10*60*10 + (ord(ss[2]) - ord('0'))*60*10 +
			(ord(ss[4]) - ord('0'))*10*10 + (ord(ss[5]) - ord('0'))*10 +
			(ord(ss[7]) - ord('0'));
	end;

	fillchar(b, sizeof(b), true);
	mm := 1000000000; l := 0;
	for i := 1 to n do begin
		k := 0;
		for j := 1 to n do
			if b[j] and ((k = 0) or (t[j]+300*(j-1) < t[k]+300*(k-1))) then
				k := j;
		b[k] := false;

		if t[k] < mm then begin
			mm := t[k];
			inc(l); aa[l] := a[k];
		end;
	end;

	for i := 1 to l do
		for j := i + 1 to l do
			if aa[j] < aa[i] then begin
				ts := aa[i]; aa[i] := aa[j]; aa[j] := ts;
			end;

	writeln(l);
	for i := 1 to l do
		writeln(aa[i]);
end.
