USING: ascii io kernel math math.parser sequences strings syntax ;

! readln 0 [ + ] reduce number>string print
readln f [ dup 72 = swap dup 81 = swap 57 = or or or ] reduce [ "YES" print ] [ "NO" print ] if
! [ 81 = ] any? [ 57 = ] any? or or 
!  [ "YES" print ] [ "NO" print ] if
! readln [ 1string print 1 1 = ] any? print
