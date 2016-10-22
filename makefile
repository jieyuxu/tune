make: main.c node.c playlist.c
	gcc main.c node.c playlist.c -o play.out

run: make
	./play.out

clean:
	rm -rf *~