USING: kernel math sequences math.parser io math.order ;
IN: factorial-example

: count2 ( n -- c )
  dup 2 rem 0 =
  [ 2 /i count2 1 + ]
  [ drop 0 ]
  if ;

: count5 ( n -- c )
  dup 5 rem 0 =
  [ 5 /i count5 1 + ]
  [ drop 0 ]
  if ;

: sum2 ( n -- s )
    iota 0 [ 1 + count2 + ] reduce ;

: sum5 ( n -- s )
    iota 0 [ 1 + count5 + ] reduce ;

: qua ( number divis flag )
  

2 f readln string>number qua
