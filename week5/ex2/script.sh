input="./data.txt"
symlink="./data.lock"
while true
do 
	if [ ! -e "${symlink}" ]; then
	ln ./data.txt ./data.lock
	while IFS= read -r var	
	do
		last="${var##* }"
	done < "$input"	
	one="1"
	echo $((last + one)) >> ./data.txt
	rm ./data.lock
	fi
	sleep 0.5
	
done
