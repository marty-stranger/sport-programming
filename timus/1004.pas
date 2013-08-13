type
	integer = longint;

const
	inf = 1000000000;

var
	n : integer;
	g : array [1..100, 1..100] of integer;
	d : array [1..100] of integer;
	p : array [1..100] of integer;

procedure Dijkstra(s : integer);
	var
		b : array [1..100] of boolean;
		u, v, i : integer;
		min : integer;

	begin
		for u := 1 to n do begin
			d[u] := g[s][u];
			p[u] := s;
			b[u] := true;
		end;
		d[s] := 0;
		p[s] := 0;
		b[s] := false;

		for i := 1 to n-1 do begin
			min := inf;
			for u := 1 to n do
				if ((b[u]) and (d[u] < min)) then begin
					v := u;
					min := d[u];
				end;

			b[v] := false;

			for u := 1 to n do
				if ((b[u]) and (d[v] + g[v][u] < d[u])) then begin
					d[u] := d[v] + g[v][u];
					p[u] := v;
				end;				
		end;
	end;	
var
	m, u, v, w, i, l, v0, w0, min, k, k1 : integer;
	cycle, cycle1 : array [1..100] of integer;
	f : boolean;

begin
	Read(n);
	while (n <> -1) do begin
		for u := 1 to n do
			for v := 1 to n do
				g[u][v] := inf;

		Readln(m);
		for i := 1 to m do begin
			Readln(u, v, l);
			if (l < g[u][v]) then begin
				g[u][v] := l;
				g[v][u] := l;
			end;
		end;

		min := inf;
		for u := 1 to n do begin
			Dijkstra(u);

			f := false;
			for v := 1 to n do
				for w := 1 to n do
					if ((d[v] + d[w] + g[v][w] < min) and ((p[v] <> w) and (p[w] <> v))) then begin
						min := d[v] + d[w] + g[v][w];
						v0 := v; w0 := w;
						f := true;
					end;

			if (f) then begin
				v := v0; k := 0;
				while (v <> 0) do begin
					inc(k); cycle[k] := v;
					v := p[v];
				end;

				v := w0; k1 := 0;
				while (v <> 0) do begin
					inc(k1); cycle1[k1] := v;
					v := p[v];
				end;
			end;	
		end;

		if (min <> inf) then begin
			for i := 1 to k-1 do
				Write(cycle[i], ' ');
			for i := k1 downto 2 do
				Write(cycle1[i], ' ');
			Writeln(cycle1[1]);
		end else
			Writeln('No solution.');

		Read(n);	
	end;
end.
