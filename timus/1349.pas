var
	n : integer;

begin
	Read(n);

	if (n = 0) then
		Write(-1)
	else if (n = 1) then
		Write('1 2 3')
	else if (n = 2) then
		Write('3 4 5')
	else
		Write('-1');
end.
