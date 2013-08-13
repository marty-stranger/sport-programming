var
	p1, q1, a, b1, b2 : integer;
	p, q : double;

begin
	Read(p, q);
	p1 := Round(p * 100);
	q1 := Round(q * 100);

	              {this amount of people is living in Ekateringburg}
	for a := 1 to 1000000000 do begin
		b1 := (p1 * a) div 10000 + 1;		
		b2 := (q1 * a) div 10000;

		if ((q1 * a) mod 10000 = 0) then
			dec(b2);

		if (b1 <= b2) then begin
			Writeln(a);
			break;
		end;		
	end;
end.
