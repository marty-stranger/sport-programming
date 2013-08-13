{ TODO formal proof ? }
var
	n, k : integer;
begin
	read(n, k);

	if k > n then
		writeln(0)
	else
		if 2*(n mod k) > k then
			writeln((n div k)*(k*(n div k) + 2*(n mod k)) + 2*(n mod k) - k)
		else
			writeln((n div k)*(k*(n div k) + 2*(n mod k)));
end.
