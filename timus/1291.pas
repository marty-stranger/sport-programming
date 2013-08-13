var
	n, i, k : longint;
	a : array [1..1000] of longint;

	g : array [1..1000] of longint;
	next, num : array [1..10000] of longint;
	last : longint;

	first, vel : longint;

	nom, den : array [1..1000] of longint;
	v : array [1..1000] of boolean;

function GCD(a, b : longint) : longint;	
	var
		c : longint;

	begin
		while (b <> 0) do
		begin
			c := a mod b;
			a := b;
			b := c;
		end;
		GCD := a;
	end;

procedure DFS(i : longint);
	var
		j, l, gg : longint;

	begin
		v[i] := true;
		j := g[i];
		while (j <> 0) do
		begin
			l := num[j];
			if (not v[l]) then
			begin
				nom[l] := -nom[i]*a[i];
				den[l] := den[i]*a[l];
				gg := GCD(Abs(nom[l]), Abs(den[l]));

				nom[l] := nom[l] div gg;
				den[l] := den[l] div gg;

				DFS(l);
			end;

			j := next[j];
		end;
	end;

begin
	last := 0;
	Fillchar(g, sizeof(g), 0);

	Read(n);
	for i := 1 to n do
	begin
		Read(a[i]);
		Read(k);
		while (k <> 0) do
		begin
			Inc(last);
			next[last] := g[i];
			num[last] := k;
			g[i] := last;

			Inc(last);
			next[last] := g[k];
			num[last] := i;
			g[k] := last;

			Read(k);
		end;
	end;

	Read(first, vel);

	for i := 1 to n do
	begin
		nom[i] := 0;
		den[i] := 1;
	end;

	nom[first] := vel;

	Fillchar(v, sizeof(v), 0);
	DFS(first);

	for i := 1 to n do
		Writeln(nom[i], '/', den[i]);
end.
