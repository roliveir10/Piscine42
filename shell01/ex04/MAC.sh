ifconfig | grep -o 'ether.*' | cut -f2- -d ' ' | sed 's/ //'
