#!/bin/sh

while true; do
	i=i
	./gen $* > $i

	./a.out < $i > out 2> /dev/null

	if [[ $? -ne 0 ]]; then
		exit
	fi	

	./check $i out

	if [[ $? -ne 0 ]]; then
		exit
	fi	

	./tpablo < $i > ans

	a=`cat out | head -n 1`
	b=`cat ans | head -n 1`

	if [[ $a -ne $b ]]; then
		echo wroung count
		exit
	fi

	echo -e "\e[32mok\E[0m" $a $b
done

mpg123 /home/marty/torrents/Dream\ Theater/07\ Studio\ -\ 2009\ Japan\ SHM\ CD\,\ Remastered/1994-Awake\ \[SHM-CD\,\ WPCR-13485\]/08\ Lie.mp3
