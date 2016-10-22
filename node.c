#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"
#include <time.h>

song_node * make_node(char title[], char artist[]){
	song_node * new = (song_node *)malloc(sizeof(song_node));
	strcpy(new->title, title);
	strcpy(new->artist, artist);
	new->next = NULL;
	return new;
}

int length( song_node * n ){
	int c = 0;
	while (n) {
	  c++;
	  n = n->next; 
	}
	return c;
}

void print_song(song_node * ptr){
	if (!ptr)
		printf("song not found\n");
	else
		printf("artist: %s | title: %s\n", ptr->artist, ptr->title);
}

void print_list(song_node * head){
//	printf("length: %d\n", length(head));
	if (! head){
		printf("no list\n");
		return;
	}
	
	while(head){
		print_song(head);
		//print_song(head->next);
		head = head->next;
	}

}

song_node * insert_front(song_node * head, char title[], char artist[]){
	song_node * newh = (song_node *)malloc(sizeof(song_node));
	newh = make_node(title, artist);
	newh->next = head;
	return newh;
}

song_node* insert_order(song_node* head, char title[], char artist[]){
	if (!head || strcmp(artist, head->artist) < 0){ //basically the song tops the list
		return insert_front(head, title, artist);
	}

	//so the head node contains at least one entry and that the artist isnt at front
	song_node * insert = (song_node *)malloc(sizeof(song_node));
	song_node * bigb = (song_node *)malloc(sizeof(song_node));
	song_node * smallb = (song_node *)malloc(sizeof(song_node));
	smallb = head;
	bigb = head->next;

	//printf("%d", length(head));
	
	if (length(head) == 1){
		if (strcmp(artist, head->artist) != 0){
			//printf("loookie\n");
			if (strcmp(artist, head->artist) < 0)
				insert_front(head, title, artist);
			else {
				insert = make_node(title, artist);
				insert->next = NULL;
				head->next = insert;
				return head;
			}
		}
		else{
			if (strcmp(title, head->title) < 0)
				insert_front(head, title, artist);

			else {
				insert = make_node(title, artist);
				insert->next = NULL;
				head->next = insert;
				return head;
			}
		}
	}

	while (bigb){
		
		if (strcmp(title, bigb->title) == 0 && strcmp(artist, bigb->artist) == 0){
			//if same title and same artist. 
			printf("entered first\n");
			return head;
		}

		if (strcmp(artist, bigb->artist) < 0 || bigb == NULL){
			printf("entered second\n");
			insert = insert_front(bigb, title, artist);
			smallb->next = insert;
			break;
		}

		// if (bigb->next == NULL){
		// 	insert = insert_front(bigb, title, artist);
		// 	smallb->next = insert;
		// }

		if (strcmp(artist, bigb->artist) == 0){
			printf("triggered\n");
			if (strcmp(title, bigb->title) < 0){
				insert = make_node(title, artist);
				smallb->next = insert;
				insert->next = bigb;
			}
			else{
				return insert_order(bigb, title, artist);
			}
		}

		smallb = smallb->next;
		bigb = bigb->next;
		//END OF WHILE LOOP IF ARTIST IS THE SAME
	}
	//print_song(insert);
	return head;
}

song_node * remove_song(song_node * head, char title[], char artist[]){
	//returns pointer removed song after delinking it
	song_node * ret = (song_node *)malloc(sizeof(song_node));
	ret = head->next;

	//if its the first one
	if (strcmp(head->title, title) == 0 && strcmp(head->artist, artist) == 0){
		head->next = NULL;
		free(head);
		return ret;
	}
	
	return remove_song(head->next, title, artist);
}
//returns ptr to first incidence of artist
song_node* search_artist(song_node* head, char artist[]){
	if (! head)
		return NULL;

	if (strcmp(head->artist, artist) == 0)
		return head;
	
	return search_artist(head->next, artist);
}


song_node* search_song(song_node* head, char title[]){

	if (! head)
		return NULL;

	if (strcmp(head->title, title) == 0)
		return head;

	return search_song(head->next, title);
}


song_node * rand_song(song_node * head){
	int r = rand() % length(head);
	int x;
	for (x = 0; x < r; x++)
		head = head->next;
	return head;
}

song_node * free_list(song_node * head){
	song_node * ret = head;
	while (head){
		head = head->next;
		free(ret);
		ret = head;
	}
	return head;
}