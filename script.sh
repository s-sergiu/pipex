#!/bin/bash

RED="\033[0;31m"
GREEN="\033[0;32m"
ENDCOLOR="\033[0m"
PURPLE="\033[1;35m"

test_1=$(< infile ls | wc -c > outfile)
test1="< infile ls | wc -c > outfile";
test_2=$(< infile cat /dev/random | ls > outfile)
test2="< infile cat /dev/random | ls > outfile";
test_3=$(< infile /bin/ls | grep pipe > outfile)
test3="< infile /bin/ls | grep pipe > outfile";
test_4=$(< infile asasd | ls > outfile)
test4="< infile asasd | ls > outfile";
test_5=$(< infile ls | grep pipe | sadasd > outfile)
test5="< infile ls | grep pipe | sadasd > outfile";
test_6=$(< infile cat /dev/random | head -c 100 | wc -c > outfile)
test6="< infile cat /dev/random | head -c 100 | wc -c > outfile";
test_7=$(< badinfile ls | head -c 100 | wc -c > outfile)
test7="badinfile ls | head -c 100 | wc -c > outfile";
test_8=$(< infile ls | head -c 100 | wc -c > outfile)
test8="infile ls | head -c 100 | wc -c > outfile";
test_9=$(< infile ls | head -c 100 | wc -c > outfile)
test9="< infile ls | head -c 100 | wc -c > outfile";


clear
make test
clear
while true; do
	echo "Please input test number: "
	read VAR

	case $VAR in

	  1 | 0)
		touch infile;
		touch outfile;
		echo -e "$RED$test1$ENDCOLOR"
		echo -e "${RED}------------------${ENDCOLOR}"
		echo -e "${GREEN}Running bash test #1..${ENDCOLOR}"
		printf "\n"
		eval $test1;
		printf "${PURPLE}Outputting result: ${ENDCOLOR}\n\n"
		echo -e "${RED}------------------${ENDCOLOR}"
		cat outfile;
		touch infile;
		touch outfile;
		echo -e "${RED}------------------${ENDCOLOR}"
		./test $VAR
		echo -e "${RED}------------------${ENDCOLOR}"
		;;

	  2 | 0)
		touch infile;
		touch outfile;
		echo -e "$RED$test2$ENDCOLOR"
		echo -e "${RED}--------------------${ENDCOLOR}"
		echo -e "${GREEN}Running bash test #2..${ENDCOLOR}"
		printf "\n"
		eval $test2;
		printf "${PURPLE}Outputting result: ${ENDCOLOR}\n\n"
		echo -e "${RED}------------------${ENDCOLOR}"
		cat outfile
		touch infile;
		touch outfile;
		echo -e "${RED}--------------------${ENDCOLOR}"
		./test $VAR
		echo -e "${RED}--------------------${ENDCOLOR}"
		;;

	  3 | 0)
		touch infile;
		touch outfile;
		echo -e "$RED$test3$ENDCOLOR";
		echo -e "${RED}--------------------${ENDCOLOR}"
		echo -e "${GREEN}Running bash test #3..${ENDCOLOR}"
		printf "\n"
		eval $test3;
		printf "${PURPLE}Outputting result: ${ENDCOLOR}\n\n"
		echo -e "${RED}------------------${ENDCOLOR}"
		cat outfile
		touch infile;
		touch outfile;
		echo -e "${RED}--------------------${ENDCOLOR}"
		./test $VAR
		echo -e "${RED}--------------------${ENDCOLOR}"
		;;
		
	  4 | 0)
		touch infile;
		touch outfile;
		echo -e "$RED$test4$ENDCOLOR";
		echo -e "${RED}--------------------${ENDCOLOR}"
		echo -e "${GREEN}Running bash test #4..${ENDCOLOR}"
		printf "\n"
		eval $test4;
		printf "${PURPLE}Outputting result: ${ENDCOLOR}\n\n"
		echo -e "${RED}------------------${ENDCOLOR}"
		cat outfile
		touch infile;
		touch outfile;
		echo -e "${RED}--------------------${ENDCOLOR}"
		./test $VAR
		echo -e "${RED}--------------------${ENDCOLOR}"
		;;
		
	  5 | 0)
		touch infile;
		touch outfile;
		echo -e "$RED$test5$ENDCOLOR";
		echo -e "${RED}--------------------${ENDCOLOR}"
		echo -e "${GREEN}Running bash test #5..${ENDCOLOR}"
		printf "\n"
		eval $test5;
		printf "${PURPLE}Outputting result: ${ENDCOLOR}\n\n"
		echo -e "${RED}------------------${ENDCOLOR}"
		cat outfile
		touch infile;
		touch outfile;
		echo -e "${RED}--------------------${ENDCOLOR}"
		./test $VAR
		echo -e "${RED}--------------------${ENDCOLOR}"
		;;
		
	  6 | 0)
		touch infile;
		touch outfile;
		echo -e "$RED$test6$ENDCOLOR";
		echo -e "${RED}--------------------${ENDCOLOR}"
		echo -e "${GREEN}Running bash test #6..${ENDCOLOR}"
		printf "\n"
		eval $test6;
		printf "${PURPLE}Outputting result: ${ENDCOLOR}\n\n"
		echo -e "${RED}------------------${ENDCOLOR}"
		cat outfile
		touch infile;
		touch outfile;
		echo -e "${RED}--------------------${ENDCOLOR}"
		./test $VAR
		echo -e "${RED}--------------------${ENDCOLOR}"
		;;
		
	  7 | 0)
		touch infile;
		touch outfile;
		echo -e "$RED$test7$ENDCOLOR";
		echo -e "${RED}--------------------${ENDCOLOR}"
		echo -e "${GREEN}Running bash test #7..${ENDCOLOR}"
		printf "\n"
		eval $test7;
		printf "${PURPLE}Outputting result: ${ENDCOLOR}\n\n"
		echo -e "${RED}------------------${ENDCOLOR}"
		cat outfile
		touch infile;
		touch outfile;
		echo -e "${RED}--------------------${ENDCOLOR}"
		./test $VAR
		echo -e "${RED}--------------------${ENDCOLOR}"
		;;
		
	  8 | 0)
		#remove rw permissions from infile
		touch infile;
		touch outfile;
		chmod -rw infile;
		echo -e "${RED}#remove rw permissions from infile"
		echo -e "$test8${ENDCOLOR}";
		echo -e "${RED}--------------------${ENDCOLOR}"
		echo -e "${GREEN}Running bash test #8..${ENDCOLOR}"
		printf "\n"
		eval $test8;
		printf "${PURPLE}Outputting result: ${ENDCOLOR}\n\n"
		echo -e "${RED}------------------${ENDCOLOR}"
		cat outfile
		touch infile;
		touch outfile;
		echo -e "${RED}--------------------${ENDCOLOR}"
		./test $VAR
		echo -e "${RED}--------------------${ENDCOLOR}"
		chmod +rw infile;
		;;
		
	  9 | 0)
		#remove rw permissions from outfile
		touch infile;
		touch outfile;
		chmod -rw outfile
		echo -e "${RED}#remove rw permissions from outfile"
		echo -e "$test9${ENDCOLOR}";
		echo -e "${RED}--------------------${ENDCOLOR}"
		echo -e "${GREEN}Running bash test #9..${ENDCOLOR}"
		printf "\n"
		eval $test9;
		printf "${PURPLE}Outputting result: ${ENDCOLOR}\n\n"
		echo -e "${RED}------------------${ENDCOLOR}"
		cat outfile
		touch infile;
		touch outfile;
		echo -e "${RED}--------------------${ENDCOLOR}"
		./test $VAR
		echo -e "${RED}--------------------${ENDCOLOR}"
		chmod +rw outfile;
		;;

	  "")
		chmod +rw outfile;
		chmod +rw infile;
		touch infile;
		touch outfile;
		clear;
		;;

	  *)
		echo -n "unknown"
		chmod +rw outfile;
		chmod +rw infile;
		touch infile;
		touch outfile;
		break;
		;;
	esac
done
