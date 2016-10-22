#include <stdio.h>
#include <stdlib.h>
#include "tunez.h"

song_node * play[26];

void add_song(char title[], char artist[]);

int codeFor(char ch);

song_node * delete_play();
void delete_song(char title[], char artist[]);

song_node* find_artist(char artist[]);
song_node* find_song(char title[]);

void print_artist(char artist[]);
void print_letter(char letter);
void print_pl();

void shuffle();
