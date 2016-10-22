#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

int main(){

	//initialize
	int i;
	for (i = 0; i < 26; i++)
		play[0] = NULL;
 	//end initialize

	add_song("red", "taylor swift");
	add_song("closer", "chainsmokers");
	add_song("fantastic baby", "big bang");
	add_song("chasing ghosts", "against the current");
	add_song("hello", "adele");
	add_song("yolo", "chainsmokers");
	add_song("starlight", "taylor swift");
	add_song("work", "rihanna");
	//print_list(play[codeFor('c')]);
	printf("printing current playlist...\n");
	print_pl();
	printf("\nprinting all songs under 'a' artists...\n");
	print_letter('a');
	
	printf("\ndeleting t-swift's red from the playlist:\nprinting taylor swift's songs still in playlist:\n");
	delete_song("red", "taylor swift");
	print_artist("taylor swift");
	printf("\ndeleting big bang's fantastic baby from the playlist:\n");
	delete_song("fantastic baby", "big bang");
	printf("printing songs of big bang left in the playlist: ");
	print_artist("big bang");

	printf("\ntesting find artist...finding adele, rihanna, skfkjshjkfhsd\n");
	print_song(find_artist("adele"));
	print_song(find_artist("rihanna"));
	print_song(find_artist("skfkjshjkfhsd"));

	printf("\ntesting find song...finding starlight, closer\n");
	print_song(find_song("starlight"));
	print_song(find_song("closer"));
	printf("\nshuffling songs... \n");
	shuffle(3);
	printf("deleting playlist...bye bye\n");
	delete_play();

	return 0;
}
