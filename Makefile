lovemeter: lovemeter.o
	gcc lovemeter.o -o lovemeter
lovemeter.o:lovemeter.c
	gcc -c lovemeter.c

install:
	cp ./lovemeter /usr/bin/lovemeter
clean:
	rm ./lovemeter.o lovemeter
remove:
	rm /usr/bin/lovemeter
