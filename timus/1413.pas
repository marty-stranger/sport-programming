{ $n+,e+}
var
	c : char;
        x, y : double;
        cx, cy : integer;
        cfx, cfy : integer;


begin
	{assign(input, 'in'); reset(input);}

	cx := 0; cy := 0; cfx := 0; cfy := 0;
	while (not eof) do begin
        	read(c);
                if (c = '1') then begin
                	dec(cfx); dec(cfy);
                end else if (c = '2') then begin
                	dec(cy);
                end else if (c = '3') then begin
                	inc(cfx); dec(cfy);
                end else if (c = '4') then begin
                	dec(cx);
                end else if (c = '5') then begin
                end else if (c = '6') then begin
                	inc(cx);
                end else if (c = '7') then begin
                	dec(cfx); inc(cfy);
                end else if (c = '8') then begin
                	inc(cy);
                end else if (c = '9') then begin
                	inc(cfx); inc(cfy);
               end else if (c = '0') then
                	break;
        end;

        x := cx + sqrt(2)*cfx / 2;
        y := cy + sqrt(2)*cfy / 2;

        writeln(x : 0 : 10, ' ', y : 0 : 10);
end.
