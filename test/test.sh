#!/bin/bash

# A little tester I whipped up. Test files are from Mazoise's tester.

# Colors
DEFAULT="\033[0m"
GREEN="\033[0;32m"
RED="\033[0;31m"

# The tester will test every file you put in the files/ folder...
files=$(ls files)

# ...with every buffer size in this list :
sizes=(1 2 3 4 10 32 64 100 1000 9999)

for size in ${sizes[@]}
do
	# Compilation line. Change it if you need to. Keep the main though, it's made to test against cat.
	clang -Wall -Wextra -Werror -o gnl -D BUFFER_SIZE=$size -I ../  ../*.c main.c
	printf "=== BUFFER SIZE %-4d ===\n" $size

	for file in ${files[@]}
	do
		cat files/$file > a
		./gnl files/$file > b
		diff a b > c
		# This checks if c is empty. If it is, then cat and your output is the same !
		if [ -s "c" ]
		then
			printf "%-17s : [${RED}FAIL${DEFAULT}]\n" $file
		else
			printf "%-17s : [${GREEN}OK${DEFAULT}]\n" $file
		fi
		rm -f a b c
		sleep 0.1
	done

	printf "\n"
	rm -f gnl
done
