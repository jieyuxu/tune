#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

int codeFor(char ch) {
	return ch - 'a';
}

void print_artist(char artist[]){
	print_list(search_artist(play[codeFor(artist[0])], artist));

}
void print_letter(char letter){
	print_list(play[codeFor(letter)]);
}

void print_pl(){
	int x;
	for (x = 0; x < 26; x++)
		print_list(play[x]);
}

void add_song(char title[], char artist[]){
	play[codeFor(artist[0])] = insert_order(play[codeFor(artist[0])], title, artist);
}

void delete_song(char title[], char artist[]){
	play[codeFor(artist[0])] = remove_song(play[codeFor(artist[0])], title, artist);
}

song_node* find_artist(char artist[]){
	return search_artist(play[codeFor(artist[0])], artist);
}
song_node* find_song(char title[]){
	int x;
	for (x = 0; x < 26; x++){
		if (search_song(play[x], title))
			return search_song(play[x], title);
	}
	
}

void shuffle(int l){
	int r;
	srand(time(NULL));
	while (l > 0){
		r = rand() % 26;
		// printf("%d\n", r);
		if (play[r]){
			print_song(rand_song(play[r]));
			l--;
		}

	}

	
}

song_node * delete_play(){
	int x;
	for (x = 0; x < 26; x++)
		free_list(play[x]);
	return 0;
}
