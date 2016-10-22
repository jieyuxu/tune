#ifndef TUNEZ_H
#define TUNEZ_H

typedef struct n{ 
  char title[256];
  char artist[256];
  struct song_node *next;
} song_node;

void print_list( song_node * );
void print_song(song_node *);

int length( song_node * );

song_node * make_node(char title[], char artist[]);

song_node * insert_front(song_node *, char title[], char artist[]);
song_node* insert_order(song_node* , char title[], char artist[]);

song_node * remove_song(song_node *, char title[], char artist[]);

song_node* search_artist(song_node* , char artist[]);
song_node* search_song(song_node* , char title[]);

song_node * rand_song(song_node *);

song_node * free_list(song_node * );
#endif

