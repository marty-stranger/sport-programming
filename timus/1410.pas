const
	let : set of char = ['a'..'z', 'A'..'Z'];

type
	integer = longint;

function max(a, b : integer) : integer;
	begin
        	if (a > b) then
                	max := a
                else
                	max := b;
        end;

var
	k, i : integer;
        ch : char;
	a, c : array [-1..100000] of integer;

begin
	{assign(input, 'in'); reset(input);}
	k := 0;

        read(ch);
        while (not eof) and not (ch in let) do
             	read(ch);

	while (not eof) do begin
        	inc(k);

                a[k] := 0;
		while (ch in let) do begin
                        inc(a[k]);
                        if (eof) then
                        	break;
                        read(ch);
                end;

                while (not eof) and not (ch in let) do
                	read(ch);
	end;

        c[-1] := 0;
        c[0] := 0;
        for i := 1 to k do
        	c[i] := max(c[i-2] + a[i], c[i-1]);

        write(c[k]);
end.
