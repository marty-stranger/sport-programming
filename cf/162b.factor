USING: formatting io kernel math math.parser ;

IN: template

: pr ( a -- )
   dup dup 0 >
   [ 2 /i pr 2 rem number>string "%d" printf ]
   [ drop drop ]
   if ;
!  dup dup 0 >
!  [ 2 / pr 2 rem print ]
!  when ;

readln string>number pr
  
