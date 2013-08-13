#!/bin/sh

for i in i.*; do
	echo -n test $i' '
	./a.out < $i > out 2> /dev/null

	if [[ $? -ne 0 ]]; then
		continue
	fi	

	./check $i out

	if [[ $? -ne 0 ]]; then
		continue
	fi	

	./tpablo < $i > ans

	a=`cat out | head -n 1`
	b=`cat ans | head -n 1`

	if [[ $a -ne $b ]]; then
		echo wrong count
		continue
	fi

	echo -e "\e[32mok\E[0m" $a $b
done

rm out ans
