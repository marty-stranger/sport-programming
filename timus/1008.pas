const 
	dx : array [1..4] of integer = (1,  0, -1,  0);
	dy : array [1..4] of integer = (0,  1,  0, -1);
	dr : array [1..4] of char = ('R', 'T', 'L', 'B');

var
	v : integer;
	a : array [0..11, 0..11] of boolean;
	qr, qw : integer;
	qx, qy : array [1..100] of integer;
	x, y, i : integer;

procedure Encode;
	var
		n, x0, y0 : integer;	

	begin
		n := v;
		FillChar(a, sizeof(a), false);
		for i := 1 to n do begin
			Read(x, y);
			a[x][y] := true;

			if (i = 1) then begin
				x0 := x;
				y0 := y;
			end;
		end;

		qr := 0; qw := 0;
		inc(qw); qx[qw] := x0; qy[qw] := y0;

		a[x0][y0] := false;
		Writeln(x0, ' ', y0);

		while (qr <> qw) do begin
			inc(qr); x := qx[qr]; y := qy[qr];

			for i := 1 to 4 do
				if (a[x + dx[i]][y + dy[i]]) then begin
					inc(qw); qx[qw] := x + dx[i]; qy[qw] := y + dy[i];
					Write(dr[i]);
					a[x + dx[i]][y + dy[i]] := false;
				end;
			if (qr <> n) then	
				Writeln(',')
			else
				Writeln('.');
		end;
		
	end;

procedure Decode;
	var
		c : char;

	begin
		Fillchar(a, sizeof(a), false);

		x := v; Readln(y);

		qr := 0; qw := 0;
		inc(qw); qx[qw] := x; qy[qw] := y;

		while (qr <> qw) do begin
			inc(qr); x := qx[qr]; y := qy[qr];
			a[x][y] := true;

			Read(c);	
			while (not (c in [',', '.'])) do begin
				case (c) of
					'R' : i := 1;
					'T' : i := 2;
					'L' : i := 3;
					'B' : i := 4;
				end;

				inc(qw);
				qx[qw] := x + dx[i]; qy[qw] := y + dy[i];				

				Read(c);
			end;
			Readln;
		end;

		Writeln(qr);
		for x := 1 to 10 do
			for y := 1 to 10 do
				if (a[x][y]) then
					Writeln(x, ' ', y);
	end;	

begin
	Read(v);

	if (eoln) then
		Encode
	else
		Decode;

end.
