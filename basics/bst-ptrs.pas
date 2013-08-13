type
	pInt = ^integer;
	
var
	f, root : integer;
	v, l, r : array [1..10000] of integer;

function treeFind(x : integer) : pInt;
var
	i : ^integer;
begin
	i := @root;
	while (i^ <> 0) and (v[i^] <> x) do
		if x < v[i^] then
			i := @l[i^]
		else
			i := @r[i^];

	treeFind := i;
end;

procedure treeDelete(i : pInt);
var
	j : ^integer;
begin
	if (l[i^] = 0) and (r[i^] = 0) then
		i^ := 0
	else if l[i^] = 0 then
		i^ := r[i^]
	else if r[i^] = 0 then
		i^ := l[i^]
	else begin
		j := @r[i^];
		while l[j^] <> 0 do
			j := @l[j^];
		v[i^] := v[j^];
		j^ := r[j^];
	end;
end;

procedure treePrint;
	procedure rec(i : integer);
	begin
		if i <> 0 then begin
			rec(l[i]);
			write(v[i], ' ');
			rec(r[i]);
		end;
	end;

begin
	rec(root);
	writeln;
end;


var
	c : char;
	x : integer;
	i : ^integer;

begin
	f := 0;
	root := 0;

	while not seekeof do begin
		read(c);
		if c <> 'p' then
			read(x);

		case c of
		'i':
			begin
				i := treeFind(x);
				inc(f); v[f] := x; l[f] := 0; r[f] := 0;
				i^ := f;
			end;
		'd':
			treeDelete(treeFind(x));
		'f':
			writeln('find: ', treeFind(x)^);
		'p':
			treePrint;
		end;
	end;
end.
