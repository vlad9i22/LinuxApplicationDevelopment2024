#!/bin/bash

if [ $1 ];
then
	delay=$1
else
	delay=0.01
fi

inp=$(cat)
line_width=$(echo $inp | cal | wc | awk '{print $3}')
temp_execute=$(mktemp)
i=0
j=0
while IFS= read -r cur_str;
do
	i=$((i+1))
	hex_str=$(echo "$cur_str" | xxd -g 1 -p | sed 's\..\& \g') 
	for letter in $hex_str
		do
			real_letter=$(echo -n $letter | xxd -r -p)
			j=$((j+1))
			echo -n "tput cup $i $j; printf '$real_letter'" >> $temp_execute
			if ! [ "$real_letter" = " " ]
			then
				echo ";sleep $delay" >> $temp_execute
			else
				echo >> $temp_execute
			fi
		done
		j=0
done <<< $inp
run=${temp_execute}_run
echo "tput clear" > $run
shuf $temp_execute >> $run
chmod +x $run
echo "tput cup $((line_width+1)) 0" >> $run
$run
rm -f $temp_execute $run

