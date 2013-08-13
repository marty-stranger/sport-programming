var
	f, ri : integer;
	v, l, r : array [1..100000] of integer;

procedure treeInsert(x : integer);
	procedure doInsert(var i : integer);
	begin
		if i = 0 then begin
			i := f; f := l[f];
			v[i] := x; l[i] := 0; r[i] := 0;
			exit;
		end;

		if x < v[i] then
			doInsert(l[i])
		else
			doInsert(r[i]);
	end;
begin
	doInsert(ri);
end;

function find(x : integer) : integer;
var
	i : integer;
begin
	i := ri;
	while (i <> 0) and (v[i] <> x) do
		if x < v[i] then
			i := l[i]
		else
			i := r[i];

	find := i;
end;

procedure treeDelete(x : integer);
	function deleteMin(var i : integer) : integer;
	begin
		if l[i] = 0 then begin
			deleteMin := v[i];
			i := r[i];
		end else
			deleteMin := deleteMin(l[i]);

	end;

	procedure doDelete(var i : integer);
	begin
		if i <> 0 then begin
			if x < v[i] then
				doDelete(l[i])
			else if x > v[i] then
				doDelete(r[i])
			else if (l[i] = 0) and (r[i] = 0) then
				i := 0
			else if l[i] = 0 then
				i := r[i]
			else if r[i] = 0 then
				i := l[i]
			else
				v[i] := deleteMin(r[i]);
		end;
	end;
begin
	doDelete(ri);
end;

procedure print;
	procedure doPrint(i : integer);
	begin
		if i <> 0 then begin
			doPrint(l[i]);
			write(v[i], ' ');
			doPrint(r[i]);
		end;
	end;
begin
	doPrint(ri);
	writeln;
end;

var
	c : char;
	i, x : integer;

begin
	f := 1;
	for i := 1 to 100000 - 1 do
		l[i] := i + 1;
	l[100000] := 0;

	ri := 0;

	while not seekeof do begin
		read(c);
		if c <> 'p' then
			read(x);

		case c of
		'i':
			treeInsert(x);
		'd':
			treeDelete(x);
		'f':
			writeln('find: ', find(x));
		'p':
			print;
		end;
	end;
end.
