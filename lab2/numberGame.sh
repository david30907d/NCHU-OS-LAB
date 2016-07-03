#!/bin/bash
#Program:
#	User first inputs a target number.Then the player need to guess the targetnumber.
#       Keep narrowing down the number range until the player guessing the right target number
#History:
#2016/7/3       BaconYao First release
#Main
	match="no"
	lowNum=1
	upNum=10
	#Ask function
	askNum () {
		while [ "${match}" != "yes" ]; do
                        #User input number
                        echo -n "Please enter a number between ${lowNum} and ${upNum} : "; read guessNum
                        #gess number out of range
                        if [ "${guessNum}" -gt "${upNum}" -o "${guessNum}" -lt "${lowNum}" ]; then
                                echo "Error input.Please try again!"
                        #Match the target
                        elif [ "${guessNum}" == "$1" ]; then
                                echo "Bingo!"
                                match="yes"
                        elif [ "${guessNum}" == "${upNum}" ]; then
                                upNum=`expr ${upNum} - 1 `
                        elif [ "${guessNum}" == "${lowNum}" ]; then
                                lowNum=`expr ${lowNum} + 1 `
  			#${1} = Argument 1
			elif [ "${guessNum}" -lt "${1}" ]; then
                                lowNum=${guessNum}
                        elif [ "${guessNum}" -gt "${1}" ]; then
                                upNum=${guessNum}
                        fi
                done    	

	}

    	#Use argument to set target number. ${1}=target number
	if [ "${#}" == "1" ]; then
		askNum ${1}
	#Do not use argument to set target number
	elif [ "${#}" == "0" ]; then
        	read -p "Please enter a target number between 1 to 10: " targetNum
		if [ "${targetNum}" -gt "${upNum}" -o "${targetNum}" -lt "${lowNum}"  ]; then
			echo "Target number out of range!Try again!"
			exit 1	
		fi
		askNum ${targetNum}
	fi
	
