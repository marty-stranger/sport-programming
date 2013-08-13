type
	tstr = string [200];

var
	n, i : integer;
	c : array [1..4] of integer;
	s, ss : tstr;
	l : array [1..4, 1..1000] of tstr;
	
begin
	readln(n);

	c[1] := 0; c[2] := 0; c[3] := 0; c[4] := 0;
	for i := 1 to n do begin
		readln(s);
		readln(ss);

		if (ss = 'Slytherin') then begin
			inc(c[1]);
			l[1][c[1]] := s;
		end else if (ss = 'Hufflepuff') then begin
			inc(c[2]);
			l[2][c[2]] := s;
		end else if (ss = 'Gryffindor') then begin
			inc(c[3]);
			l[3][c[3]] := s;
		end else begin
			inc(c[4]);
			l[4][c[4]] := s;
		end;
	end;

	writeln('Slytherin:');
	for i := 1 to c[1] do
		writeln(l[1][i]);

	writeln;
	writeln('Hufflepuff:');
	for i := 1 to c[2] do
		writeln(l[2][i]);

	writeln;
	writeln('Gryffindor:');
	for i := 1 to c[3] do
		writeln(l[3][i]);

	writeln;
	writeln('Ravenclaw:');
	for i := 1 to c[4] do
		writeln(l[4][i]);
end.
