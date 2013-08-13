var
	n, i, j : integer;
	fa, fb : longint;
	max : int64;

begin
	Read(n);
	Read(fa); max := 0;
	for i := 1 to n-1 do begin
		Read(fb);

		if (abs(int64(fb) - fa) > max) then begin
			max := abs(int64(fb) - fa);
			j := i;

		end;

		fa := fb;
	end;

	Writeln(j, ' ', j+1);
end.
