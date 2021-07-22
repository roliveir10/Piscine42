echo $FT_NBR1 | sed 'y/\\"?!/1234/' | sed "y/'/0/" | xargs echo "ibase=5; $FT_NBR2 +" | sed 'y/mrdoc/01234/' | xargs echo "obase=13;" | bc | sed 'y/0123456789ABC/gtaio luSnemf/'
