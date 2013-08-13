#!/bin/sh

i=1

while true; do
	(( i++ ))

	echo $i

	c=`cat t | wc -l`
	(( c++ ))

	if [[ $i -gt $c ]]; then
		break;
	fi

	sed "$i d" i > t

	./a.out < t > out 2> /dev/null

	if [[ $? -ne 0 ]]; then
		echo del
		cp t i
		continue
	fi

	./check t out

	if [[ $? -ne 0 ]]; then
		echo del
		cp t i
		continue
	fi

	./tpablo < t > ans

	a=`cat out | head -n 1`
	b=`cat ans | head -n 1`

	if [[ $a -ne $b ]]; then
		echo del
		cp t i
		continue
	fi

done
