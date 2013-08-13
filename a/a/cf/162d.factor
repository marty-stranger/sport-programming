USING: ascii io kernel math math.parser sequences strings ;

readln [ dup digit? [ drop ] [ 1string print ] if ] each

! 17 iota [ number>string print ] each
  
